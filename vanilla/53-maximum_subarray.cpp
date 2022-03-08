class Solution {
public:
    int maxSubArray(vector<int>& nums) {
		//动规：dp[i]表示以第i处结尾的子串最大和，对于第i处，既可为第i-1处子串之延伸
		//又可于此另起炉灶，两种情况取和最大者
        int maxS = -1e6, preS = -1e6;
        for(const auto& i: nums){
            preS = max(preS + i, i);
            maxS = max(maxS, preS);
        }
        return maxS;
    }
};