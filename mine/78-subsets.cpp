class Solution {
public:
    vector<vector<int>> ans;
    vector<int> set;

    void recursiveBody(vector<int>& nums, int i, int n){
        if(i == n) ans.emplace_back(set);
        else{
            set.emplace_back(nums[i]);
            recursiveBody(nums, i+1, n);
            set.pop_back();
            recursiveBody(nums, i+1, n);
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        recursiveBody(nums, 0, nums.size());
        return ans;
    }
};