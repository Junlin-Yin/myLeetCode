class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(), [](vector<int>& i1, vector<int>& i2){return i1[0] < i2[0];});
        ans.emplace_back(intervals[0]); intervals.erase(intervals.begin());
        for(auto i: intervals){
            vector<int> &pre_i = ans.back();
            if(pre_i[1] >= i[0])    pre_i[1] = max(pre_i[1], i[1]);
            else                    ans.emplace_back(i);
        }
        return ans;
    }
};