class Solution {
public:
    bool canJump(vector<int>& nums) {
        int rmost = 0, last = nums.size() - 1;
        //最远覆盖范围
        for(int i = 0; i <= rmost && rmost < last; ++i)
            rmost = max(rmost, i + nums[i]);
        return rmost >= last;
    }
};