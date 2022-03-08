class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int sz = nums.size(), l = 0, r = sz-1, mid, first, second;
        while(l < r){
            mid = (l + r) >> 1;
            if(nums[mid] < target)  l = mid + 1;
            else                    r = mid;
        }
        first = (l < sz && nums[l] == target) ? l : -1;
        if(first != -1){
            l = first; r = sz-1;
            while(l < r){
                mid = (l + r) >> 1;
                if(nums[mid] > target)  r = mid - 1;
                else                    l = mid + 1;
            }
            second = (nums[l] == target) ? l : l - 1;
        }else{
            second = -1;
        }
        vector<int> ans = {first, second};
        return ans;
    }
};