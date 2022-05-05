class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int x = 0, y = m - 1;
        bool flag = false;
        while(x < n && y >= 0){
            int pivot = matrix[x][y];
            if(pivot > target)      --y;
            else if(pivot < target) ++x;
            else {flag = true; break;}
        }
        return flag;
    }
};