class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = n >> 1;
        for(int i = 0; i < m; ++i){
            for(int j = i; j < n - i - 1; ++j){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i] = tmp;
            }
        }
    }
};