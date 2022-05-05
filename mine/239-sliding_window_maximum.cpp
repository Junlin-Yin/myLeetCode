class MaxHeap {
private:
    vector<int> a;
    int k;
public:
    MaxHeap(vector<int>& nums, int k) : a(k + 1), k(k) {
        for(int i = 0; i < k; ++i)      a[i + 1] = nums[i];
        for(int i = k / 2; i >= 1; --i) percDown(i);
    }

    void percDown(int s) {
        int ele = a[s];
        int i, child;
        for(i = s; i * 2 <= k; i = child){
            child = (i << 1);
            if(child < k && a[child + 1] > a[child]) ++child;
            if(a[child] > ele)  a[i] = a[child];
            else                break;
        }
        a[i] = ele;
    }

    void percUp(int s){
        int ele = a[s];
        int i, parent;
        for(i = s; i > 1; i = parent){
            parent = (i >> 1);
            if(a[parent] < ele) a[i] = a[parent];
            else                break;
        }
        a[i] = ele;
    }

    int getMax(){
        return a[1];
    }

    void changeVal(int oldv, int newv){
        if(oldv != newv){
            int i;
            for(int i = 1; i <= k && a[i] != oldv; ++i);	//这一步是性能瓶颈，被卡时间
            if(oldv > newv) percDown(i);
            else            percUp(i);
        }
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        // cout << n << endl;
        MaxHeap heap(nums, k);
        vector<int> ans;
        for(int i = 0; i + k < n; ++i){
            ans.emplace_back(heap.getMax());
            heap.changeVal(nums[i], nums[i + k]);
        }
        ans.emplace_back(heap.getMax());
        return ans;
    }
};