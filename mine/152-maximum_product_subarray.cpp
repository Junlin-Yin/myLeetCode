class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxp, minp, ret;
        maxp = minp = ret = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            int n = nums[i];
            if(n > 0){
                maxp = max(maxp * n, n);
                minp = min(minp * n, n);
            }else{
                int new_maxp = max(minp * n, n);
                int new_minp = min(maxp * n, n);
                maxp = new_maxp;
                minp = new_minp;
            }
            ret = max(maxp, ret);
        }
        return ret;
    }
};