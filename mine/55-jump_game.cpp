class Solution {
public:
    bool canJump(vector<int>& nums) {
		//naive dp
        int n = nums.size();
        vector<bool> dp(n, false);
        dp[n - 1] = true;
        for(int i = n - 2; i >= 0; --i){
            for(int j = min(n-1-i, nums[i]); j > 0; --j){
                dp[i] = dp[i] || dp[i+j];
                if(dp[i]) break;
            }
        }
        return dp[0];
    }
};

class Solution {
public:
    bool canJump(vector<int>& nums) {
		//queue
        int n = nums.size();
        queue<int>  q;
        vector<bool> v(n, false);
        q.push(0); v[0] = true;
        while(!q.empty()){
            int next_i, i = q.front(); q.pop();
            for(int j = 1; j <= nums[i] && (next_i = i + j) < n; ++j){
                if(!v[next_i]){
                    v[next_i] = true;
                    q.push(next_i);
                }
            }
            if(q.back() == n - 1) break;
        }
        return v[n - 1];
    }
};