class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int ns = s.size(), np = p.size(), differ = 0;
        vector<int> hash(26, 0), indices;
        for(const char& c: p)   ++hash[c - 'a'];
        for(const int& n: hash) differ += (n > 0);
        for(int i = 0; i < ns; ++i) {
            if((--hash[s[i] - 'a']) == 0)                   --differ;
            if(i >= np && (++hash[s[i - np] - 'a']) == 1)   ++differ;
            if(i >= np - 1 && !differ)
                indices.emplace_back(i - np + 1);
        }
        return indices;
    }
};