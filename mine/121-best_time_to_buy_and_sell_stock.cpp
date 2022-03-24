class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mincost = prices[0], maxprofit = 0;
        for(int i = 1; i < prices.size(); ++i){
            maxprofit = max(maxprofit, prices[i] - mincost);
            mincost = min(mincost, prices[i]);
        }
        return maxprofit;
    }
};