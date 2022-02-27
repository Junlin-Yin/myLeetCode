class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int ni, nj, nk, prev_ni, prev_nj, sum;
        for(int i=0; i<nums.size(); prev_ni=nums[i],++i){
            ni = nums[i];
            if(i != 0 && ni == prev_ni)  continue;
            int k = nums.size() - 1;
			//认识到ni固定后，符合3sum的nj与nk是相向发展的，因此可以将nj与nk的遍历并列处理，是为双指针
            for(int j=i+1; j<nums.size(); prev_nj=nums[j],++j){
                nj = nums[j];
                if(j != i+1 && nj == prev_nj)  continue;
                for(nk = nums[k]; j < k && (sum = ni+nj+nk) > 0; nk = nums[--k]);
                if(j >= k) break;
                if(sum == 0){
                    vector<int> triplet = {ni, nj, nk};
                    ans.push_back(triplet);
                }
            }
        }
        return ans;
    }
};