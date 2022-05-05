class Solution {
public:
    string decodeString(string s) {
        string decode;
        int n = s.size(), i1, i2, i3;
        for(i1 = 0; i1 < n && islower(s[i1]); ++i1)
            decode.push_back(s[i1]);
        if(i1 == n) return decode;
        i2 = s.find_first_of('[', i1);
        int times = stoi(s.substr(i1, i2 - i1));
        int left = 0;
        for(i3 = i2; i3 < n; ++i3){
            if(s[i3] == '[')        ++left;
            else if(s[i3] == ']')   --left;
            if(!left)   break;
        }
        string in = decodeString(s.substr(i2 + 1, i3 - i2 - 1));
        for(int i = 0; i < times; ++i)  decode += in;
        decode += decodeString(s.substr(i3 + 1));
        return decode;
    }
};