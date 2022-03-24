class Solution {
public:
    bool isSubstring(unordered_map<char, int> mm){
        bool flag = true;
        for(const auto& p: mm)  if(!(flag = flag && p.second <= 0)) break;
        return flag;
    }

    string minWindow(string s, string t) {
        int m = s.size(), n = t.size(), l = 0, r = 0, minlen = 1e6, minl;
        if(m < n)   return "";
        unordered_map<char, int> mm;
        for(const auto& c: t)   ++mm[c];
        bool firstMatch = false;
        char c = '#';
        while(r <= m){
            // cout << l << " " << r << endl;
            bool flag = (!firstMatch) ? isSubstring(mm) : mm[c] <= 0;
            if(flag){
                firstMatch = true;
                if(minlen > r - l){
                    minlen = r - l;
                    minl = l;
                }
                if(mm.find(s[l]) != mm.end()){
                    c = s[l++];
                    ++mm[c];
                }
                while(l < m && mm.find(s[l]) == mm.end()) ++l;
            }else{
                while(r < m && mm.find(s[r]) == mm.end()) ++r;
                if(r < m)   --mm[s[r]];
                ++r;
            }
        }
        return minlen == 1e6 ? "" : s.substr(minl, minlen);
    }
};