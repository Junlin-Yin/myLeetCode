class Solution {
public:
    int uniquePaths(int m, int n) {
        // ans = Combination_{m+n-2}^{m-1}
        long ans = 1;
        for(int i = 1; i < m; ++i)     ans = ans * (i + n - 1) / i;
        return ans;
    }
};