class Solution {
public:
    vector<vector<int>> ans;

    void recursiveBody(vector<int>& nums, int sz, vector<int>& perm){
        if(sz == 0)    { ans.push_back(perm); return; }
        for(int i = 0; i < sz; ++i){
            perm.push_back(nums[i]);
            nums.erase(nums.begin()+i);
            recursiveBody(nums, sz-1, perm);
            nums.insert(nums.begin()+i, perm.back());
            perm.pop_back();  
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> perm;
        recursiveBody(nums, nums.size(), perm);
        return ans;
    }
};