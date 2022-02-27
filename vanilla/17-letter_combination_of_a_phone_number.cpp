class Solution {
public:
    //注意map初始化定义方式
    map<char, string> m{
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"},
    };

    vector<string> recursiveBody(vector<string> prev, string digits){
        if(digits.size() == 0) return prev;
        string c_digits = m[digits[0]];
        vector<string> curr;
        if(prev.size() == 0)    prev = {""};
        for(auto s: prev){
            for(auto d: c_digits){  //注意string是特殊的vector<char>
                string ss = s;
                ss.push_back(d);
                curr.push_back(ss);
            }
        }
        return recursiveBody(curr, digits.substr(1));
    }

    vector<string> letterCombinations(string digits) {
        return recursiveBody(vector<string>(), digits);
    }
};