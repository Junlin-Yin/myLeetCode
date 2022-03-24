class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size(), i;
        vector<bool> v(n + 1, false);   v[0] = true;
        for(i = 0; i <= n; ++i) {
            if(!v[i])   continue;
            for(const string& w: wordDict) {
                int len = w.size();
                if(i + len <= n && !v[i + len] && s.substr(i, len) == w)
                    v[i + len] = true;
            }
        }
        return v[n];
    }
};