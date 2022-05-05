class Solution {
public:
    vector<string> ansf;
    vector<string> ansb;
    unordered_set<string> mem;

    void forwardRecursive(string &s, int i0){
        int n = s.size(), left = 0, i;
        for(i = i0; i < n && left >= 0; ++i){
            if(s[i] == '(')         ++left;
            else if(s[i] == ')')    --left;
        }
        if(left < 0){
            //delete one ')'
            for(int j = 0; j < i; ++j){
                if(s[j] == ')'){
                    s.erase(s.begin() + j);
                    if(!mem.count(s)){
                        mem.insert(s);
                        forwardRecursive(s, i - 1);
                    }
                    s.insert(s.begin() + j, ')');
                }
            }
        }else{
            ansf.emplace_back(s); 
        }
    }

    void backwardRecursive(string &s, int i0){
        int n = s.size(), right = 0, i;
        for(i = i0; i >= 0 && right >= 0; --i){
            if(s[i] == '(')         --right;
            else if(s[i] == ')')    ++right;
        }
        if(right < 0){
            //delete one '('
            for(int j = n - 1; j > i; --j){
                if(s[j] == '('){
                    s.erase(s.begin() + j);
                    if(!mem.count(s)){
                        mem.insert(s);
                        backwardRecursive(s, i);
                    }
                    s.insert(s.begin() + j, '(');
                }
            }
        }else{
            ansb.emplace_back(s); 
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        forwardRecursive(s, 0);
        for(string& ss: ansf)
            backwardRecursive(ss, ss.size() - 1);
        return ansb;
    }
};