class Solution {
public:
    bool findExpect(vector<int>& nums, int left, int right, int expect){
        if(left > right)    return false;
        int middle = (left + right) / 2;
        if(nums[middle] == expect)
            return true;
        else if(nums[middle] > expect)
            return findExpect(nums, left, middle-1, expect);
        else
            return findExpect(nums, middle+1, right, expect);
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); ++i){
            if(i > 0 && nums[i] == nums[i-1])    continue;
            if(nums[i] > 0) break;
            for(int j=nums.size()-1; j>i; --j){
                if(j < nums.size() - 1 && nums[j] == nums[j+1])    continue;
                int expect = -(nums[i] + nums[j]);	//未注意到expect随着j的缩小在增大，故而遗憾没能用上双指针
                if(expect > nums[j]) break;
                if(findExpect(nums, i+1, j-1, expect)){
                    vector<int> triplet = {nums[i], expect, nums[j]};
                    ans.push_back(triplet);
                }     
            }
        }
        return ans;
    }
};