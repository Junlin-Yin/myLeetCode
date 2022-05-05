class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int N = nums.size();
        int V = accumulate(nums.begin(), nums.end(), 0) - target;
        if(V & 1 || V < 0)   return 0;
        V >>= 1;
        vector<int> dp(V + 1, 0);
        dp[0] = 1;
        for(int i = 0; i < N; ++i){
            int ni = nums[i];
            for(int j = V; j >= ni; --j)
                dp[j] += dp[j - ni];
        }
        return dp[V];
    }
};