class Solution1 {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        //身高从低到高考虑，用indices数组作辅助可降低时间复杂度至O(NlogN)
        int N = people.size();
        sort(people.begin(), people.end(), [](vector<int>& p1, vector<int>& p2){
            return (p1[0] != p2[0]) ? p1[0] < p2[0] : p1[1] > p2[1];
        });
        vector<vector<int>> ans(N);
        vector<int> indices(N);
        for(int i = 0; i < N; ++i)  indices[i] = i;
        for(int i = 0; i < N; ++i){
            int k = people[i][1];
            ans[indices[k]] = people[i];
            indices.erase(indices.begin() + k);
        }
        return ans;
    }
};

class Solution2 {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        //身高从高到低考虑，代码简洁但时间复杂度只有O(N^2)
        sort(people.begin(), people.end(), [](vector<int>& p1, vector<int>& p2){
            return p1[0] > p2[0] || p1[0] == p2[0] && p1[1] < p2[1];
        });
        vector<vector<int>> ans;
        for(const auto& p: people)
            ans.insert(ans.begin() + p[1], p);
        return ans;
    }
};