class Solution1 {
public:
    int maximalSquare(vector<int>& hist) {
        int n = hist.size(), hist_max = 0;
        stack<int> st;
        st.push(0);
        for(int i = 1; i < n; ++i){
            int hi = hist[i];
            while(hi < hist[st.top()]){
                int j = st.top(); st.pop();
                int wj = i - st.top() - 1;
                int hj = hist[j];
                hist_max = max(hist_max, (int)pow(min(wj, hj), 2));
            }
            st.push(i);
        }
        return hist_max;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), matrix_max = 0;
        vector<int> hist(n + 2, 0);
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j)
                hist[j + 1] = (matrix[i][j] == '0') ? 0 : hist[j + 1] + 1;
            int hist_max = maximalSquare(hist);
            matrix_max = max(matrix_max, hist_max);
        }
        return matrix_max;
    }
};

class Solution2 {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), maxa = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(matrix[i][j] == '0'){
                    dp[i][j] = 0;
                }else{
                    dp[i][j] = 1;
                    if(i > 0 && j > 0){
                        int a = min(dp[i-1][j], dp[i][j-1]);
                        if(matrix[i-a][j-a] == '1') dp[i][j] += a;
                        else                        dp[i][j] += a - 1;
                    }
                }
                maxa = max(maxa, dp[i][j]);
            }
        }
        return maxa * maxa;
    }
};