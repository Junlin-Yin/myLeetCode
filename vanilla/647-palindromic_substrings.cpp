class Solution1 {
public:
    int countSubstrings(string s) {
        //中心扩展
        int cnt = 0, n = s.size(), k = (n << 1) - 1;
        for(int i = 0; i < k; ++i){
            for(int l = (i >> 1), r = l + (i & 1); l >= 0 && r < n && s[l] == s[r]; --l, ++r, ++cnt);
        }
        return cnt;
    }
};

class Solution2 {
public:
    int countSubstrings(string s) {
        //马拉车
        string t = "$#";
        for(const char& c: s){
            t += c;
            t += "#";
        }
        t += "!";   //首尾字符不一致，以便简化后续扩展的约束条件

        int n = t.size(), iMax, rMax = 0, cnt = 0;
        vector<int> f(n);   //f[i] := 以t[i]为中心的最大回文半径，从1起计
        for(int i = 1; i < n - 1; ++i){
            //初始化f[i]
            f[i] = (i <= rMax) ? min(rMax - i + 1, f[(iMax << 1) - i]) : 1;
            //中心扩展
            for(int l = i - f[i], r = i + f[i]; t[l] == t[r]; --l, ++r) ++f[i];
            //更新参照位置和对应的最右边界
            if(i + f[i] - 1 > rMax){
                iMax = i;
                rMax = i + f[i] - 1;
            }
            //去#计数，满足整除2的关系
            cnt += (f[i] >> 1);
        }
        return cnt;
    }
};