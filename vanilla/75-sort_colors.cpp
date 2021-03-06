class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        for(int i = 0; i <= r; ++i){
            while(nums[i] == 2 && i < r)    swap(nums[i], nums[r--]);
            while(nums[i] == 0 && l < i)    swap(nums[i], nums[l++]);
        }
    }
};