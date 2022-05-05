class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1); dp[0] = 0;
        for(int i = 1; i <= amount; ++i){
            int prev_min = INT_MAX;
            for(const int& c: coins){
                if(i - c >= 0)  prev_min = min(prev_min, dp[i - c]);
            }
            dp[i] = prev_min == INT_MAX ? prev_min : prev_min + 1;
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};