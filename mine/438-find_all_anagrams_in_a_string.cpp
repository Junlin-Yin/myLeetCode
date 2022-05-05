class Solution {
public:

    bool check(unordered_map<char, int>& hash){
        bool flag = true;
        for(const auto& p: hash){
            if(p.second > 0){
                flag = false;
                break;
            }
        }
        return flag;
    }

    vector<int> findAnagrams(string s, string p) {
        int ns = s.size(), np = p.size();
        unordered_map<char, int> hash;
        vector<int> indices;
        for(const char& c: p)   ++hash[c];
        for(int i = 0; i < ns; ++i) {
            if(hash.count(s[i]))
                --hash[s[i]];
            if(i >= np && hash.count(s[i - np]))
                ++hash[s[i - np]];
            if(i >= np - 1 && check(hash))
                indices.emplace_back(i - np + 1);
        }
        return indices;
    }
};