class Solution {
public:
    int prevProfit(vector<int>& dp, int j){
        return j < 0 ? 0 : dp[j];
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size(), maxpro = 0;
        vector<int> dp(n, 0);
        for(int i = 1; i < n; ++i){
            int min_cost = INT_MAX;
            for(int j = i - 1; j >= 0; --j){
                min_cost = min(min_cost, prices[j]);
                dp[i] = max(dp[i], prevProfit(dp, j - 2) + max(0, prices[i] - min_cost));
                maxpro = max(maxpro, dp[i]);
            }
        }
        return maxpro;
    }
};