class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		//记载字符最近一次出现的位置，关注窗口右界的迭代
        map<char, int> charmap;
        int length = 0, left = 0, right = 0;
        while(right < s.length()){
            char c = s.at(right);
            if(charmap.find(c) != charmap.end() && charmap[c] >= left){
                left = charmap[c] + 1;
            }
            charmap[c] = right++;
            length = max(length, right - left);
        }
        return length;
    }
};