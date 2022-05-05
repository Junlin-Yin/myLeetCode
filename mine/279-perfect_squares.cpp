class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1);
        dp[0] = 0;
        for(int i = 1; i <= n; ++i){
            int prev_min = INT_MAX, j2;
            for(int j = 1; (j2 = j * j) <= i; ++j)
                prev_min = min(prev_min, dp[i - j2]);
            dp[i] = prev_min + 1;
        }
        return dp[n];
    }
};