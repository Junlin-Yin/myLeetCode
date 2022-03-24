class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        for(int i = 0; i <= n; ++i)
            if(i < 2)   dp[i] = 1;
            else        for(int j = 0; j < i; ++j)  dp[i] += dp[j]*dp[i-1-j];
        return dp[n];
    }
};