class Solution {
public:
    int maximalRectangle(vector<int>& hist) {
        int n = hist.size(), hist_max = 0;
        stack<int> st;
        st.push(0);
        for(int i = 1; i < n; ++i){
            int hi = hist[i];
            while(hi < hist[st.top()]){
                int j = st.top(); st.pop();
                int wj = i - st.top() - 1;
                int hj = hist[j];
                hist_max = max(hist_max, hj * wj);
            }
            st.push(i);
        }
        return hist_max;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), matrix_max = 0;
        vector<int> hist(n + 2, 0);
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j)
                hist[j + 1] = (matrix[i][j] == '0') ? 0 : hist[j + 1] + 1;
            int hist_max = maximalRectangle(hist);
            matrix_max = max(matrix_max, hist_max);
        }
        return matrix_max;
    }
};