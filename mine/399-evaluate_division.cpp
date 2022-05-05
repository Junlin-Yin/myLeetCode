class Solution {
public:
    struct Node{
        string next;
        double val;
    };
    unordered_map<string, vector<Node>> graph;

    double dfs(string s, string t, unordered_set<string>& visited){
        if(s == t)  return 1;
        double ans = -1;
        for(const auto& node: graph[s]){
            if(!visited.count(node.next)){
                visited.insert(node.next);
                double ret = dfs(node.next, t, visited);
                if(ret >= 0){
                    ans = node.val * ret;
                    break;
                }
                visited.erase(node.next);
            }
        }
        return ans;
    }

    double calcQuery(string s, string t){
        if(graph.find(s) == graph.end() || graph.find(t) == graph.end())    return -1;
        unordered_set<string> visited;
        visited.insert(s);
        return dfs(s, t, visited);
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int N = equations.size(), M = queries.size();
        for(int i = 0; i < N; ++i){
            string ai = equations[i][0], bi = equations[i][1];
            double val = values[i];
            graph[ai].push_back({bi, val});
            graph[bi].push_back({ai, 1 / val});
        }
        vector<double> ans;
        for(int i = 0; i < M; ++i){
            ans.emplace_back(calcQuery(queries[i][0], queries[i][1]));
        }
        return ans;
    }
};