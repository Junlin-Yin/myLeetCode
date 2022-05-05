class Solution {
public:
    int m, n;
    void bfs(vector<vector<char>>& grid, int i, int j){
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = '0';
        while(!q.empty()){
            i = q.front().first, j = q.front().second;
            q.pop();
            if(i > 0 && grid[i - 1][j] == '1'){
                q.push({i - 1, j}); 
                grid[i - 1][j] = '0';
            }
            if(i < m - 1 && grid[i + 1][j] == '1'){
                q.push({i + 1, j});
                grid[i + 1][j] = '0';
            }
            if(j > 0 && grid[i][j - 1] == '1'){
                q.push({i, j - 1});
                grid[i][j - 1] = '0';
            }
            if(j < n - 1 && grid[i][j + 1] == '1'){
                q.push({i, j + 1});
                grid[i][j + 1] = '0';
            }
        }
    }

    void dfs(vector<vector<char>>& grid, int i, int j){
        if(grid[i][j] == '0')   return;
        grid[i][j] = '0';
        if(i > 0 && grid[i - 1][j] == '1')      dfs(grid, i - 1, j);
        if(i < m - 1 && grid[i + 1][j] == '1')  dfs(grid, i + 1, j);
        if(j > 0 && grid[i][j - 1] == '1')      dfs(grid, i, j - 1);
        if(j < n - 1 && grid[i][j + 1] == '1')  dfs(grid, i, j + 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        m = grid.size(), n = grid[0].size();
        int cnt = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == '0')   continue;
                ++cnt;
                dfs(grid, i, j);
                // bfs(grid, i, j);
            }
        }
        return cnt;
    }
};