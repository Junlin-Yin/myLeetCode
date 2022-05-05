class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1, 0);
        int two_power = 1;
        for(int i = 1; i <= n; ++i){
            if((dp[i] = dp[i % two_power] + 1) == 1)
                two_power = i;
        }
        return dp;
    }
};