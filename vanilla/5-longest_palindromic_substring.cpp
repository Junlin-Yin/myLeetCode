class Solution {
public:
    string longestPalindrome(string s) {
        int N = s.length(), maxlen, maxi;
        bool table[N][N];
        // vector<vector<bool>> dp(n, vector<bool>(n));     use STL template to define dp table
        for(int L=1; L<=N; ++L){
            bool flag = false;
            for(int i=0; i<=N-L; ++i){
                int j = i + L - 1;
                switch(L){
                    case 1: table[i][j] = true; break;
                    case 2: table[i][j] = (s[i] == s[j]); break;
                    default: table[i][j] = (table[i+1][j-1] && (s[i] == s[j]));
                }
                if(!flag && table[i][j]){
                    flag = true;
                    maxlen = L;
                    maxi = i;
                }
            }
        }
        return s.substr(maxi, maxlen);
    }
};