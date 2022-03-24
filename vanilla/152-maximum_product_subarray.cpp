class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxp, minp, ret;
        maxp = minp = ret = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            int n = nums[i], maxp_n = maxp * n, minp_n = minp * n, new_maxp, new_minp;
            new_maxp = max(max(maxp_n, minp_n), n);
            new_minp = min(min(maxp_n, minp_n), n);
            maxp = new_maxp;
            minp = new_minp;
            ret = max(maxp, ret);
        }
        return ret;
    }
};