class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target, int L, int R, int U, int D) {
        if(L > R || U > D)  return false;
        int x = (L + R) >> 1, y = (U + D) >> 1, pivot = matrix[y][x];
        if(pivot < target){
            return (searchMatrix(matrix, target, x + 1, R, y + 1, D) ||
                    searchMatrix(matrix, target, L, x, y + 1, D) ||
                    searchMatrix(matrix, target, x + 1, R, U, y));
        }else if(pivot > target){
            return (searchMatrix(matrix, target, L, x - 1, U, y - 1) ||
                    searchMatrix(matrix, target, L, x - 1, y, D) ||
                    searchMatrix(matrix, target, x, R, U, y - 1));
        }else{
            return true;
        }
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return searchMatrix(matrix, target, 0, matrix[0].size() - 1, 0, matrix.size() - 1);
    }
};