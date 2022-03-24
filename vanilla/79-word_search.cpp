class Solution {
public:
    struct coord{int x, y;};
    int m, n;
    vector<coord> ds = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& v, coord curr, string& word, int k){
        if(k == word.size())    return true;
        bool flag = false;
        for(const auto& d: ds){
            int nx = curr.x + d.x, ny = curr.y + d.y;
            if(nx >= 0 && ny >= 0 && nx < m && ny < n && !v[nx][ny] && board[nx][ny] == word[k]){
                v[nx][ny] = true;
                if((flag = dfs(board, v, {nx, ny}, word, k+1)) == true) break;
                v[nx][ny] = false;
            }
        }
        return flag;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size();
        vector<vector<bool>> v(m, vector<bool>(n, false));
        bool flag = false;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(board[i][j] == word[0]){
                    v[i][j] = true;
                    if((flag = dfs(board, v, {i, j}, word, 1)) == true)    break;
                    v[i][j] = false;
                }
            }
            if(flag)    break;
        }
        return flag;
    }
};