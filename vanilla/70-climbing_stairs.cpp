class Solution1 {
public:
    vector<vector<long>> multiply(vector<vector<long>> A, vector<vector<long>> B){
        return {{A[0][0] * B[0][0] + A[0][1] * B[1][0], A[0][0] * B[0][1] + A[0][1] * B[1][1]}, \
                {A[1][0] * B[0][0] + A[1][1] * B[1][0], A[1][0] * B[0][1] + A[1][1] * B[1][1]}};
    }

    vector<vector<long>> qpow(vector<vector<long>> M, int p){
        vector<vector<long>> A = {{1, 0}, {0, 1}};
        while(p){
            if(p & 1)   A = multiply(A, M);
            M = multiply(M, M);
            p >>= 1;
        }
        return A;
    }

    int climbStairs(int n) {
		//齐次递推式->转换矩阵->矩阵快速幂
        vector<vector<long>> M = {{1, 1}, {1, 0}};
        vector<vector<long>> Mn = qpow(M, n);
        return Mn[1][0] + Mn[1][1];
    }
};

class Solution2 {
public:
    int climbStairs(int n) {
		//通项公式
        double sqrt5 = sqrt(5);
        return round((pow((1+sqrt5)/2.0, n+1) - pow((1-sqrt5)/2.0, n+1))/sqrt5);
    }
};