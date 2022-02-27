class Solution {
public:
    vector<string> recursiveBody(vector<string> prev, string digits){
        if(digits.size() == 0) return prev;
        char c = digits[0];
        vector<char> c_digits;
        switch(c){
            case '2': c_digits = {'a', 'b', 'c'}; break;
            case '3': c_digits = {'d', 'e', 'f'}; break;
            case '4': c_digits = {'g', 'h', 'i'}; break;
            case '5': c_digits = {'j', 'k', 'l'}; break;
            case '6': c_digits = {'m', 'n', 'o'}; break;
            case '7': c_digits = {'p', 'q', 'r', 's'}; break;
            case '8': c_digits = {'t', 'u', 'v'}; break;
            case '9': c_digits = {'w', 'x', 'y', 'z'};
        }
        vector<string> curr;
        if(prev.size() == 0)    prev = {""};
        for(auto s: prev){
            for(auto d: c_digits){
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