class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for(int k = 1; k < n; ++k){
            for(int i = 0; i < n - k; ++i){
                int j = i + k, maxele = 0;
                for(int mid = i + 1; mid < j; ++mid)
                    maxele = max(maxele, nums[mid] * nums[i] * nums[j] + dp[i][mid] + dp[mid][j]);
                dp[i][j] = maxele;
            }
        }
        return dp[0][n - 1];
    }
};