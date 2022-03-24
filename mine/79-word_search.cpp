class Solution {
public:
    struct coord{int x, y;};
    map<char, int> m1, m2;
    int m, n;

    vector<coord> getPossiblePos(coord curr){
        vector<coord> pos;
        if(curr.x < 0 && curr.y < 0){
            for(int i = 0; i < m; ++i){
                for(int j = 0; j < n; ++j){
                    pos.push_back({i, j});
                }
            }
        }else{
            if(curr.x > 0)      pos.push_back({curr.x-1, curr.y});
            if(curr.y > 0)      pos.push_back({curr.x, curr.y-1});
            if(curr.x < m - 1)  pos.push_back({curr.x+1, curr.y});
            if(curr.y < n - 1)  pos.push_back({curr.x, curr.y+1});            
        }
        return pos;
    }

    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& v, coord curr, string& word, int k){
        // cout << curr.x << " " << curr.y << endl;
        if(k == word.size())    return true;
        bool flag = false;
        vector<coord> pos = getPossiblePos(curr);
        for(const auto& p: pos){
            if(!v[p.x][p.y] && board[p.x][p.y] == word[k]){
                v[p.x][p.y] = true;
                if((flag = dfs(board, v, p, word, k+1)) == true) break;
                v[p.x][p.y] = false;
            }
        }
        return flag;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size();
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                ++m1[board[i][j]];
            }
        }
        for(int k = 0; k < word.size(); ++k)    ++m2[word[k]];
        for(const auto& p: m2){
            if(m1[p.first] < p.second)  return false;
        }
        vector<vector<bool>> v(m, vector<bool>(n, false));
        return dfs(board, v, {-1, -1}, word, 0);
    }
};