class Solution {
public:

    static bool cmp(vector<int>& p1, vector<int>& p2){
        return p1[0] > p2[0];
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        priority_queue<vector<int>, vector<vector<int>>, decltype(&cmp)> heap(cmp);
        list<pair<int, vector<int>>> ind;
        for(const auto& p: people){
            if(p[1] == 0)   heap.push(p);
            else            ind.emplace_back(p[1], p);
        }
        vector<vector<int>> ans;
        while(!heap.empty()){
            int hi = heap.top()[0];
            ans.push_back(heap.top());
            heap.pop();
            for(auto it = ind.begin(); it != ind.end(); ){
                if(it->second[0] <= hi && (--it->first) == 0){
                    heap.push(it->second);
                    it = ind.erase(it);
                }else{
                    ++it;
                }
            }
        }
        return ans;
    }
};