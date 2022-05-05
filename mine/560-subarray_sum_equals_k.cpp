class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefix;
        prefix[0] = 1;
        int ret = 0, sum = 0;
        for(const int& n: nums) {
            sum += n;
            if(prefix.count(sum - k))
                ret += prefix[sum - k];
            ++prefix[sum];
        }
        return ret;
    }
};