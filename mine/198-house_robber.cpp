class Solution {
public:
    int rob(vector<int>& nums) {
        int N = nums.size();
        if(N <= 2)  return *max_element(nums.begin(), nums.end());
        int prev3 = nums[0], prev2 = nums[1], prev1 = nums[0] + nums[2], curr;
        int ret = max(prev3, max(prev2, prev1));
        for(int i = 3; i < N; ++i){
            curr = max(prev2, prev3) + nums[i];
            ret = max(curr, ret);
            prev3 = prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return ret;
    }
};