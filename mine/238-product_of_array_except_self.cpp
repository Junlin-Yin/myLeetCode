class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int N = nums.size();
        vector<int> ans(N, 1);
        for(int i = 1; i < N; ++i) 
            ans[i] = ans[i - 1] * nums[i - 1];
        int s = 1;
        for(int i = N - 2; i >= 0; --i) {
            ans[i] *= s * nums[i + 1];
            s *= nums[i + 1];
        }
        return ans;
    }
};