class Solution {
    struct UnionFind{
        unordered_map<string, pair<string, double>> hash;

        void RegisiterVariable(string& name){
            if(!Exist(name))
                hash[name] = {name, 1.0};
        }

        bool Exist(string& name){
            return hash.find(name) != hash.end();
        }

        pair<string, double> Find(string& name){
            if(hash[name].first != name){
                auto ret = Find(hash[name].first);
                hash[name].first = ret.first;
                hash[name].second *= ret.second;
            }
            return hash[name];
        }

        void Union(string& root1, string& root2, double val){
            hash[root1] = {root2, val};
        }
    };
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int N = equations.size(), M = queries.size();
        UnionFind uf;
        for(int i = 0; i < N; ++i){
            string a = equations[i][0], b = equations[i][1];
            uf.RegisiterVariable(a);
            uf.RegisiterVariable(b);
            auto pa = uf.Find(a);
            auto pb = uf.Find(b);
            double val = values[i];
            uf.Union(pa.first, pb.first, val * pb.second / pa.second);
        }
        vector<double> ans;
        for(int i = 0; i < M; ++i){
            double q = -1;
            string c = queries[i][0], d = queries[i][1];
            if(uf.Exist(c) && uf.Exist(d)){
                auto pc = uf.Find(c);
                auto pd = uf.Find(d);   
                q = (pc.first == pd.first) ? (pc.second / pd.second) : -1;            
            }
            ans.emplace_back(q);     
        }
        return ans;
    }
};