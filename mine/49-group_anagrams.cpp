class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<string, vector<string>> m;
        for(auto s: strs){
            string key = s;
            sort(key.begin(), key.end());
            m[key].push_back(s);
        }
        for(auto v: m)
            ans.push_back(v.second);
        return ans;
    }
};