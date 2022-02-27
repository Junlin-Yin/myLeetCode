class Solution {
public:
    bool isPalindromic(string s){
        if(s.length() == 1) return true;
        string r = s;
        reverse(r.begin(), r.end());
        return r == s;
    }

    string longestPalindrome(string s) {
        string max_sub;
        int left, right, max_length=0;
        for(left=0; left<s.length(); ++left){
            char c = s.at(left);
            right = left + max_length - 1;
            while(true){
                for(++right; right<s.length() && s.at(right)!=c; ++right);
                if(right >= s.length()) break;
                string sub = s.substr(left, right+1-left);
                if(isPalindromic(sub)){
                    int length = sub.length();
                    if(max_length < length){
                        max_length = length;
                        max_sub = sub;
                    }                    
                }
            }
        }
        return max_sub;
    }
};