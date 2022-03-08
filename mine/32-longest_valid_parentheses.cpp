class Solution {
public:
    int longestValidParentheses(string s) {
		return ON_stack(s);
		// return ON3_dp(s);
    }

    int ON_stack(string s){
        int lefts = 0, maxlen = 0;
        map<int, int> steps;
        for(int i=0; i<s.size(); ++i){
            if(s[i] == '('){
                if(steps.find(lefts) == steps.end())
                    steps[lefts] = i;
                ++lefts;
            }else{
                if(steps.find(--lefts) != steps.end())
                    maxlen = max(maxlen, i - steps[lefts] + 1);
                for(auto it = steps.begin(); it != steps.end();){
                    if(it->first > lefts)    it = steps.erase(it);
                    else ++it;
                }
            }
        }
        return maxlen;
    }

    int ON3_dp(string s){
        int L = s.size(), maxlen = 0;
        vector<vector<bool>> dp(L, vector<bool>(L+1));
        for(int i=0; i<L; ++i)  dp[i][i] = true;
        for(int l=2; l<=L; l+=2){
            for(int i=0; i<=L-l; ++i){
                int j = i + l;
                dp[i][j] = dp[i+1][j-1] && (s[i] == '(') && (s[j-1] == ')');
                for(int k=i+2; k<=j-2&&!(dp[i][j]=dp[i][j]||(dp[i][k]&&dp[k][j])); k+=2);
                if(dp[i][j] && maxlen < l)  maxlen = l;
            }
        }
        return maxlen;
    }
};