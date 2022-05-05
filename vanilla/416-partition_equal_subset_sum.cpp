class Solution {
public:
    bool canPartition(vector<int>& nums) {
		//不带空间优化的0-1背包
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum & 1) return false;
        int N = nums.size(), V = sum >> 1;
        vector<vector<bool>> dp(N + 1, vector<bool>(V + 1, false));
        dp[0][0] = true;
        for(int i = 1; i <= N; ++i){
            for(int j = 0; j <= V; ++j){
                dp[i][j] = dp[i - 1][j] || (j >= nums[i - 1]) && dp[i - 1][j - nums[i - 1]];
            }
        }
        return dp[N][V];
    }
};

class Solution {
public:
    bool canPartition(vector<int>& nums) {
		//带有空间优化的0-1背包
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum & 1) return false;
        int N = nums.size(), V = sum >> 1;
        vector<bool> dp(V + 1, false);
        dp[0] = true;
        for(int i = 1; i <= N; ++i){
            int ni = nums[i - 1];
            for(int j = V; j >= ni; --j){
                dp[j] = dp[j] || dp[j - ni];
            }
        }
        return dp[V];
    }
};