class Solution {
public:
    int countSubstrings(string s) {
        int cnt = 0, n = s.size();
        vector<bool> dp(n + 1, false);
        for(int i = n - 1; i >= 0; --i){
            for(int k = n - i; k >= 1; --k){
                dp[k] = s[i] == s[i + k - 1];
                if(k > 2)   dp[k] = dp[k] && dp[k - 2];
                cnt += (int)dp[k];                
            }
        }
        return cnt;
    }
};