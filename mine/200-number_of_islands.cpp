class Solution {
public:
    int m, n;
    void bfs(vector<vector<char>>& grid, unordered_set<int>& s, int i, int j){
        queue<int> q;
        q.push(i * n + j);
        s.insert(i * n + j);
        while(!q.empty()){
            int topid = q.front(); q.pop();
            int topi = topid / n, topj = topid % n;
            if(topi > 0 && grid[topi - 1][topj] == '1' && !s.count(topid - n)){
                s.insert(topid - n);
                q.push(topid - n);
            }
            if(topi < m - 1 && grid[topi + 1][topj] == '1' && !s.count(topid + n)){
                s.insert(topid + n);
                q.push(topid + n);
            }
            if(topj > 0 && grid[topi][topj - 1] == '1' && !s.count(topid - 1)){
                s.insert(topid - 1);
                q.push(topid - 1);
            }
            if(topj < n - 1 && grid[topi][topj + 1] == '1' && !s.count(topid + 1)){
                s.insert(topid + 1);
                q.push(topid + 1);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        unordered_set<int> s;
        m = grid.size(), n = grid[0].size();
        int cnt = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == '0' || s.count(i * n + j))   continue;
                ++cnt;
                bfs(grid, s, i, j);
            }
        }
        return cnt;
    }
};