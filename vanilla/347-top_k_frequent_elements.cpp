class Solution {
public:
    static bool cmp(pair<int, int>& p1, pair<int, int>& p2){
        return p1.second > p2.second;   //最小堆
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for(const int& n: nums) ++cnt[n];
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> heap(cmp);
        //维持堆的容量不超过k，保证堆中元素始终为当前的top k
        for(const auto& p: cnt){
            if(heap.size() < k){
                heap.push(p);
            }else if(heap.top().second < p.second){
                heap.pop();
                heap.push(p);
            }
        }
        vector<int> ans;
        for(int i = 0; i < k; ++i){
            ans.emplace_back(heap.top().first);
            heap.pop();
        }
        return ans;
    }
};

class Solution {
public:
    void KLargestElement(vector<pair<int, int>>& a, int k){
        //反正不要求返回顺序，用快排卡第k-1大的数，它和它左侧的所有元素即为所求
        int l = 0, r = a.size() - 1, i, j;
        while(l <= r){
            int chosen = (l + r) >> 1;
            swap(a[l], a[chosen]);
            i = l + 1; j = r;
            while(true){
                for(; i <= j && a[i].second >= a[l].second; ++i);
                for(; i <= j && a[j].second <= a[l].second; --j);
                if(i > j)   break;
                swap(a[i], a[j]);
            }
            swap(a[l], a[j]);
            if(j < k)       l = j + 1;
            else if(j > k)  r = j - 1;
            else break;
        }
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for(const int& n: nums) ++cnt[n];
        vector<pair<int, int>> a(cnt.begin(), cnt.end());
        KLargestElement(a, k - 1);
        vector<int> ans;
        for(int i = 0; i < k; ++i)  ans.emplace_back(a[i].first);
        return ans;
    }
};