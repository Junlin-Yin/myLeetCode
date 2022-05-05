class Solution {
public:
    int hammingDistance(int x, int y) {
        int n = x ^ y, d;
        for(d = 0; n; n >>= 1)  d += (n & 1);
        return d;
    }
};