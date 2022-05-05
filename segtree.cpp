#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class SegTree{
private:
	const int n;
	vector<T> tree, mark;

	void build(int p, int l, int r, vector<T>& v){
		if(l > r){
			return;
		}else if(l == r){
			tree[p] = v[l];
		}else{
			int m = (l + r) >> 1;
			build(p << 1 | 0, l,     m, v);
			build(p << 1 | 1, m + 1, r, v);
			tree[p] = tree[p << 1] + tree[p << 1 | 1];			
		}
	}

	T query(int p, int l, int r, int cl, int cr){
		if(r < cl || l > cr)	return (T)0;
		if(l <= cl && cr <= r)	return tree[p];
		push_down(p, cl, cr);
		int cm = (cl + cr) >> 1;
		return query(p << 1, l, r, cl, cm) + query(p << 1 | 1, l, r, cm + 1, cr);
	}

	void add_point(int p, T d, int i, int cl, int cr){
		if(i < cl || i > cr)	return;
		if(cl < cr){
			int cm = (cl + cr) >> 1;
			if(i <= cm)	add(p << 1 | 0, d, i, cl, cm);
			else		add(p << 1 | 1, d, i, cm + 1, cr);
		}
		tree[p] += d;
	}

	void add_range(int p, T d, int l, int r, int cl, int cr){
		if(r < cl || l > cr)	return;
		if(l <= cl && r >= cr){
			tree[p] += (cr - cl + 1) * d;
			mark[p] += d;
		}else{
			push_down(p, cl, cr);
			int cm = (cl + cr) >> 1;
			if(l <= cm)	add_range(p << 1 | 0, d, l, r, cl, cm);
			if(r > cm)	add_range(p << 1 | 1, d, l, r, cm + 1, cr);
			tree[p] = tree[p << 1] + tree[p << 1 | 1];
		}
	}

	void push_down(int p, int cl, int cr){
		if(mark[p] != 0){
			int cm = (cl + cr) >> 1;
			mark[p << 1 | 0] += mark[p];
			mark[p << 1 | 1] += mark[p];
			tree[p << 1 | 0] += (cm - cl + 1) * mark[p];
			tree[p << 1 | 1] += (cr - cm) * mark[p];
			mark[p] = 0;			
		}
	}

public:
	SegTree(vector<T>& v) : n(v.size()), tree(n << 2, 0), mark(n << 2, 0){
		build(1, 0, n-1, v);
	}

	T query(int l, int r){
		return query(1, l, r, 0, n - 1);
	}

	void add_point(T d, int i){
		add_point(1, d, i, 0, n - 1);
	}

	void add_range(T d, int l, int r){
		add_range(1, d, l, r, 0, n - 1);
	}

	void print(void){
		for(int i = 1; i < tree.size(); ++i)	cout << tree[i] << " "; cout << endl;
		for(int i = 1; i < mark.size(); ++i)	cout << mark[i] << " "; cout << endl;
	}
};

int main(void){
	vector<int> v = {7,2,4,6,9,3,0,5,1,8};
	SegTree<int> st(v);
	cout << st.query(2, 8) << endl;
	st.add_range(10, 0, 4);
	st.print();
	st.add_range(10, 2, 7);
	st.print();
	cout << st.query(4, 6) << endl;
	st.print();
	return 0;
}