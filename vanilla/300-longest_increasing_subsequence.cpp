class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> LeastTails;
        for(const int& n: nums){
            //find first index i s.t. LeastTails[i] >= n
            auto it = lower_bound(LeastTails.begin(), LeastTails.end(), n);
            if(it != LeastTails.end())  *it = n;
            else                        LeastTails.emplace_back(n);
        }
        return LeastTails.size();
    }
};