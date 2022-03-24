class Solution1 {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxlen = 0, e;
        unordered_set<int> set(nums.begin(), nums.end());
        for(const auto& s: set) {
            if(set.find(s - 1) != set.end())  continue;
            for(e = s + 1; set.find(e) != set.end(); ++e);
            maxlen = max(maxlen, e - s);
        }
        return maxlen;
    }
};

class Solution2 {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxlen = 0;
        map<int, int> hash;
        map<int, int>::iterator it, nit;
        for(const auto& n: nums)    hash[n] = 1;
        for(it = hash.begin(); it != hash.end(); it = nit) {
            nit = it; ++nit;
            while(nit != hash.end() && it->first + it->second == nit->first){
                it->second += nit->second;
                nit = hash.erase(nit);
            }
            maxlen = max(maxlen, it->second);
        }
        return maxlen;
    }
};