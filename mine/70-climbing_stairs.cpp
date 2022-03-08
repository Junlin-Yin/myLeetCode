class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2)  return n;
        int dp_prev2=1, dp_prev1=2, dp;
        for(int i=2; i<n; ++i){
            dp = dp_prev1 + dp_prev2;
            dp_prev2 = dp_prev1;
            dp_prev1 = dp;
        }
        return dp;
    }
};