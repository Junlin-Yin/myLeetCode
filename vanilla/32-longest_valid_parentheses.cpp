class Solution1 {	//动态规划
public:
    int longestValidParentheses(string s) {
        int sz = s.size(), maxlen = 0;
		//dp[i]: 以第i个字符结束的有效字串的最长长度，i=1,2,...,sz
        vector<int> dp(sz+1, 0);
        for(int i=1; i<sz; ++i){
            if(s[i] == ')'){
                if(s[i-1] == '(')
					//...()
                    dp[i+1] = dp[i-1] + 2;
                else if(i - dp[i] - 1 >= 0 && s[i - dp[i] - 1] == '(')
					//...((...))
                    dp[i+1] = dp[i] + 2 + dp[i - dp[i] - 1];
                maxlen = max(maxlen, dp[i+1]);
            }
        }
        return maxlen;
    }
};

class Solution2 {	//堆栈
public:
    int longestValidParentheses(string s) {
        int sz = s.size(), maxlen = 0;
        stack<int> st;
		//栈底保留最后一个尚未匹配右括号的下标，其余保存尚未匹配的左括号下标
        st.push(-1);
        for(int i=0; i<sz; ++i){
            if(s[i] == '(') st.push(i);
            else{
				//难点：先弹后算长度
                st.pop();
                if(st.empty())  st.push(i);                 //匹配失败
                else maxlen = max(maxlen, i - st.top());    //匹配成功
            }
        }
        return maxlen;
    }
};