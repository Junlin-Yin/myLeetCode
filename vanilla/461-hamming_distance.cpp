class Solution1 {
public:
    int hammingDistance(int x, int y) {
        //x & x - 1去掉最低位的1
        int n = x ^ y, d;
        for(d = 0; n; n &= n - 1)  ++d;
        return d;
    }
};

class Solution2 {
public:
    int hammingDistance(int x, int y) {
        return __builtin_popcount(x ^ y);
    }
};