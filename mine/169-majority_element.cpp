class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> hash;
        for(const int& n: nums) ++hash[n];
        int N = nums.size(), ret;
        for(const auto& p: hash){
            if(p.second > N / 2){
                ret = p.first; break;
            }
        }
        return ret;
    }
};