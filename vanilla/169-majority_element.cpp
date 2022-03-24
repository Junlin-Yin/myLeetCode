class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cand, cnt = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(!cnt)    cand = nums[i];
            if(cand == nums[i]) ++cnt;
            else                --cnt;
        }
        return cand;
    }
};