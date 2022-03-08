class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> m;    //map对标红黑树，unordered_map对标哈希表
        for(auto s: strs){
            string key = s;
            sort(key.begin(), key.end());
            m[key].emplace_back(s);                 //用emplace_back代替push_back
        }
        for(auto v: m)
            ans.emplace_back(v.second);
        return ans;
    }
};