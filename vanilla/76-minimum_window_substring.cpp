class Solution {
public:
    bool isSubstring(unordered_map<char, int>& mm, char c, bool firstMatched){
        if(firstMatched)    return mm[c] <= 0;
        for(const auto& p: mm)
            if(p.second > 0)    return false;
        return true;
    }

    string minWindow(string s, string t) {
        unordered_map<char, int> mm;
        for(const auto& c: t)   ++mm[c];
        int n = s.size(), l = 0, r = 0, minlen = 1e6, minl;
        bool firstMatched = false;
        char c = 0;
        while(true){
            while(r < n && mm.find(s[r]) == mm.end())   ++r;
            if(r >= n)   break;
            --mm[s[r++]];
            while(isSubstring(mm, c, firstMatched)){
                firstMatched = true;
                if(minlen > r - l){
                    minlen = r - l;
                    minl   = l;
                }
                if(mm.find(s[l]) != mm.end()){
                    c = s[l++];   ++mm[c];
                }
                while(l <= r && mm.find(s[l]) == mm.end())   ++l;
                if(l > r)   break;
            }
        }
        return minlen == 1e6 ? "" : s.substr(minl, minlen);
    }
};