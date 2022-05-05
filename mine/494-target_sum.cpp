class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int N = nums.size(), S = accumulate(nums.begin(), nums.end(), 0);
        if(target < -S || target > S)   return 0;
        vector<int> dp(S * 2 + 1, 0);  // -S -> S
        vector<int> _dp = dp;
        dp[S] = 1;
        for(int i = 0; i < N; ++i){
            int ni = nums[i];
            for(int j = 0; j <= 2*S; ++j){
                _dp[j] = ((j >= ni) ? dp[j - ni] : 0) + ((j <= 2*S - ni) ? dp[j + ni] : 0);
            }
            dp = _dp;
        }
        return dp[target + S];
    }
};