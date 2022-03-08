class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.size() == 0)   return s.size() == 0;
        int i = s.size() - 1, j = p.size() - 1, i0 = -1;
        char c = p[j];
        if(c != '*')    return i >= 0 && isMatch(s.substr(0, i), p.substr(0, j)) && (c == '.' || s[i] == c);
        else{   // c == '*'
            // c = p[j-1];
            // bool flag = isMatch(s, p.substr(0, j-1));
            // if(i >= 0 && (c == '.' || s[i] == c))   flag = flag || isMatch(s.substr(0, i), p);
            // return flag;
            bool flag = false;
            c = p[--j];
            if(c >= 'a' && c <= 'z')    for(i0 = i; i0 >= 0 && s[i0] == c; --i0);
            ++i0;   //i0 == 0 or s[i0] is the first element that == c
            for(int k = s.size(); k >= i0; --k){
                if(isMatch(s.substr(0, k), p.substr(0, j))){
                    flag = true;
                    break;
                }
            }
            return flag;
        }
    }
};