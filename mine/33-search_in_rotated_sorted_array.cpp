class Solution {
public:
    int search(vector<int>& nums, int target) {
        int sz = nums.size(), l = 0, r = sz-1, k = sz - 1;
        if(nums[0] > nums[sz-1]){
            while(l <= r){
                k = (l + r) >> 1;
                if(nums[k] > nums[k+1])     break;
                if(nums[k] < nums[0])       r = k - 1;
                if(nums[k] > nums[sz-1])    l = k + 1;
            }            
        }
        r = k; l = (r + 1) % sz;
        while(nums[l] < nums[r]){
            k = l <= r ? (l + r) >> 1 : ((l + r + sz) >> 1) % sz;
            if(nums[k] < target)        l = (k + 1) % sz;
            else if(nums[k] > target)   r = k;
            else break;
        }
        return nums[l] < nums[r] ? k : ((nums[l] == target) ? l : -1);
    }
};