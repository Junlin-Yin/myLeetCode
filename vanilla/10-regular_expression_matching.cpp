class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        char c;
        vector<vector<bool>> table(m+1, vector<bool>(n+1));
        for(int i=0; i<=m; ++i) table[i][0] = (i == 0);
        for(int j=1; j<=n; ++j){
            if((c = p[j-1]) != '*'){
                for(int i=0; i<=m; ++i)
                    table[i][j] = (i > 0) && (c == '.' || c == s[i-1]) && table[i-1][j-1];
            }else{
                c = p[j-2];
                for(int i=0; i<=m; ++i){
                    table[i][j] = table[i][j-2];
                    if((i > 0) && (c == '.' || c == s[i-1]))
                        table[i][j] = table[i-1][j] | table[i][j];
                }              
            }
        }
        return table[m][n];
    }
};