class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
		//有序并查+有序哈希
        map<int, int> u;
        int s = INT_MIN, l = 0, maxlen = 0;
        for(const auto& n: nums){
            if(u.find(n) != u.end())      		continue;
            else if(u.find(n-1) != u.end())     u[n] = n-1;
            else                				u[n] = n;
            
            if(u.find(n+1) != u.end())          u[n+1] = u[n];
        }
        for(auto it = u.begin(); it != u.end(); ++it){
            it->second = u[it->second];
            if(s == it->second){
                ++l;
            }else{
                s = it->second; l = 1;
            }
            maxlen = max(l, maxlen);
        }
        return maxlen;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
		//超时
        map<long, int> m;
        m[LONG_MIN] = 0; m[LONG_MAX] = 0;
        int maxlen = 0;
        for(const auto& n: nums) {
            auto it = m.begin();
            for(; it->first <= n; ++it);    --it;
            if(it->first + it->second > n){
                continue;
            }else if(it->first + it->second == n){
                ++it->second;
            }else{
                m[n] = 1;   ++it;
            }

            auto nit = it; ++nit;
            while(it->first + it->second == nit->first){
                it->second += nit->second;
                nit = m.erase(nit);
            }
            maxlen = max(maxlen, it->second);
        }
        return maxlen;
    }
};