class Solution1 {
public:
    int findKthLargest(vector<int>& nums, int L, int R, int k){
        if(L == R)  return nums[L];
        int mid = (L + R) >> 1;		//可随机选择
        swap(nums[L], nums[mid]);
        int i = L + 1, j = R;
        while(true){
            for(; i <= j && nums[i] >= nums[L]; ++i);
            for(; i <= j && nums[j] <= nums[L]; --j);
            if(i > j)   break;
            swap(nums[i++], nums[j--]);
        }
        swap(nums[L], nums[j]);
        if(j == k - 1)      return nums[j];
        else if(j > k - 1)  return findKthLargest(nums, L, j-1, k);
        else                return findKthLargest(nums, j+1, R, k);
    }

    int findKthLargest(vector<int>& nums, int k) {
		//快排思想
        return findKthLargest(nums, 0, nums.size()-1, k);
    }
};

class Solution2 {
public:
    void percDown(vector<int>& nums, int s, int n){
        int ele = nums[s];
        int i, child;
        for(i = s; 2 * i + 1 < n; i = child){
            child = 2 * i + 1;
            if(child + 1 < n && nums[child + 1] > nums[child])  ++child;
            if(nums[child] > ele)       nums[i] = nums[child];
            else                        break;
        }
        nums[i] = ele;
    }

    int findKthLargest(vector<int>& nums, int k) {
		//堆排思想
        int n = nums.size();
        for(int i = (n - 1) / 2; i >= 0; --i)
            percDown(nums, i, n);
        for(int i = 0; i < k - 1; ++i){
            swap(nums[0], nums[n - i - 1]);
            percDown(nums, 0, n - i - 1);
        }
        return nums[0];
    }
};