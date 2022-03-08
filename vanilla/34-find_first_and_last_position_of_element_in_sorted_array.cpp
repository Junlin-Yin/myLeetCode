class Solution {
public:
    //找到非降序数组中首个大于（等于）目标数的下标
    int binarySearch(vector<int>& nums, int target, bool allow_eq){
        int sz = nums.size(), l = 0, r = sz - 1, mid;
        while(l <= r){
            mid = (l + r) >> 1;
            //r有从合格到不合格的风险，而l有从不合格到合格的希望
            if(nums[mid] > target || (allow_eq && nums[mid] >= target)) r = mid - 1;
            else                                                        l = mid + 1;
        }
        return l;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = binarySearch(nums, target, true);
        if(first >= nums.size() || nums[first] != target)   first = -1;
        int second = first == -1 ? -1 : binarySearch(nums, target, false)-1;
        vector<int> ans = {first, second};
        return ans;
    }
};