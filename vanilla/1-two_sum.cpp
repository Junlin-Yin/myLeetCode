class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        int i, j;
        for(i = 0; i < nums.size(); ++i) {
            auto it = m.find(target - nums[i]);
            if(it != m.end()){
                j = it->second; break;
            }
            m[nums[i]] = i;
        }
        return {j, i};
    }
};