class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), len = 0;
        vector<int> dp(n);
        for(int i = 0; i < n; ++i){
            int max_prev = 0;
            for(int j = 0; j < i; ++j){
                if(nums[j] < nums[i])   max_prev = max(max_prev, dp[j]);
            }
            dp[i] = max_prev + 1;
            len = max(len, dp[i]);
        }
        return len;
    }
};