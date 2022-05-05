class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> cnts(n, 0), ans;
        for(const int& i: nums) ++cnts[i - 1];
        for(int i = 0; i < n; ++i){
            if(!cnts[i])  ans.emplace_back(i + 1);
        }
        return ans;
    }
};