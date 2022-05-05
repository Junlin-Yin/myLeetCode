class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for(const int& n: nums) ++cnt[n];
        vector<pair<int, int>> tmp;
        for(const auto& p: cnt) tmp.emplace_back(p.second, p.first);
        priority_queue<pair<int, int>> heap(tmp.begin(), tmp.end());
        vector<int> ans;
        for(int i = 0; i < k; ++i){
            ans.emplace_back(heap.top().second);
            heap.pop();
        }
        return ans;
    }
};

//修正版，堆的初始化更加标准
class Solution {
public:
    static bool cmp(pair<int, int>& p1, pair<int, int>& p2){
        return p1.second < p2.second;	//小于是最大堆，大于是最小堆，反的
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for(const int& n: nums) ++cnt[n];
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> heap(cnt.begin(), cnt.end(), cmp);
        vector<int> ans;
        for(int i = 0; i < k; ++i){
            ans.emplace_back(heap.top().first);
            heap.pop();
        }
        return ans;
    }
};