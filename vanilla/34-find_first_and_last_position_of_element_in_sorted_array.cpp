class Solution {
public:
    //找到非降序数组中首个大于（等于）目标数的下标，以下两种均可
    //注意r的初始赋值、迭代式和循环条件中的取等情况
    int binarySearch(vector<int>& nums, int target, bool allow_eq){
        int l = 0, r = nums.size() - 1, mid;
        while(l <= r){
            mid = (l + r) >> 1;
            if((eq && nums[mid] < target) || (!eq && nums[mid] <= target))  l = mid + 1;
            else                                                            r = mid - 1;
        }
        return l;
    }

    int binarySearch(vector<int>& nums, int target, bool allow_eq){
        int l = 0, r = nums.size(), mid;
        while(l < r){
            mid = (l + r) >> 1;
            if((eq && nums[mid] < target) || (!eq && nums[mid] <= target))  l = mid + 1;
            else                                                            r = mid;
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