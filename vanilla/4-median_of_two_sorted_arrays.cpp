class Solution1 {
public:
    int extAt(vector<int> nums, int index, int sz){
        if(index < 0)          return -1e6;
        else if(index >= sz)   return 1e6;
        else                   return nums[index];
    }

    int findKIndexedElement(vector<int> a, vector<int> b, int k){   // k start from 0
        int m, n;
        if((m = a.size()) == 0) return b[k];
        if((n = b.size()) == 0) return a[k];
        if(k == 0)              return min(a[0], b[0]);
        if(k == 1){
            int x = max(a[0], b[0]), y = min(extAt(a, 1, m), extAt(b, 1, n));
            return min(x, y);
        }
        int minsz = min(m - 1, n - 1), i = min((k >> 1) - 1, minsz);
        if(a[i] < b[i]) return findKIndexedElement(vector<int>(a.begin()+i+1, a.end()), b, k-i-1);
        else            return findKIndexedElement(a, vector<int>(b.begin()+i+1, b.end()), k-i-1);
    }

    int findKLeastElement(vector<int> a, vector<int> b, int k){     // k start from 1
        int m, n;
        if((m = a.size()) == 0) return b[k-1];
        if((n = b.size()) == 0) return a[k-1];
        if(k == 1)              return min(a[0], b[0]);
        int minsz = min(m - 1, n - 1), i = min((k >> 1) - 1, minsz);
        if(a[i] < b[i]) return findKLeastElement(vector<int>(a.begin()+i+1, a.end()), b, k-i-1);
        else            return findKLeastElement(a, vector<int>(b.begin()+i+1, b.end()), k-i-1);      
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		//以下二者选一

		//寻找归并后数组中下标为k的元素值
        // int m = nums1.size(), n = nums2.size(), i = (m + n - 1) >> 1;
        // double median = findKIndexedElement(nums1, nums2, i);
        // if((m + n) % 2 == 0){
        //     median += findKIndexedElement(nums1, nums2, i+1);
        //     median /= 2;
        // }

		//寻找归并后数组中第k小的元素值
        int m = nums1.size(), n = nums2.size(), i = (m + n + 1) >> 1;
        double median = findKLeastElement(nums1, nums2, i);
        if((m + n) % 2 == 0){
            median += findKLeastElement(nums1, nums2, i+1);
            median /= 2;
        }
        return median;
    }
};


class Solution2 {
public:
    int extAt(vector<int> nums, int index, int sz){
        if(index < 0)          return -1e6;
        else if(index >= sz)   return 1e6;
        else                   return nums[index];
    }

    double findPartition(vector<int> a, vector<int> b, int m, int n){   // m < n
        int left = 0, right = m, i_add_j = (m + n) / 2, i, j, a_left, a_right, b_left, b_right;
        while(true){
            i = (left + right) >> 1;
            j = i_add_j - i;
            a_left = extAt(a, i-1, m), a_right = extAt(a, i, m);
            b_left = extAt(b, j-1, n), b_right = extAt(b, j, n);
            if(b_left > a_right)        left = i + 1;
            else if(a_left > b_right)   right = i - 1;
            else break;
        }
        double median = min(a_right, b_right);
        if(i_add_j << 1 == (m + n)){
            median += max(a_left, b_left);
            median /= 2;
        }
        return median;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sz1 = nums1.size(), sz2 = nums2.size();
        if(sz1 < sz2) return findPartition(nums1, nums2, sz1, sz2);
        else          return findPartition(nums2, nums1, sz2, sz1);
    }
};