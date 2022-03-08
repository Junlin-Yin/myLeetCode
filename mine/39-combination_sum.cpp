class Solution {
public:
    vector<vector<int>> ans;

    void recursiveBody(vector<int>& candidates, vector<int>& com, int target, int i0){
        if(target < 0)          return;
        else if(target == 0)    { ans.push_back(com); return; }
        else{
            int c;
            for(int i = i0; i < candidates.size() && (c = candidates[i]) <= target; ++i){
                com.push_back(c);
                recursiveBody(candidates, com, target-c, i);
                com.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> combination;
        recursiveBody(candidates, combination, target, 0);
        return ans;
    }
};