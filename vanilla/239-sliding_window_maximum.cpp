class Solution1 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		//学会使用C++ STL自带的堆结构
        int n = nums.size();
        priority_queue<pair<int, int>> heap;				//默认最大堆
															//pair数据默认采用字典序比较大小，无需用户指定
		// priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap;
															//最小堆写法
        vector<int> ans;
        for(int i = 0; i < n; ++i){
            // heap.push({nums[i], i});
            heap.emplace(nums[i], i);						//注意push与emplace的差别
            if(i < k - 1)   continue;
            while(heap.top().second + k <= i)   heap.pop();	//注意被动检测与延迟处理的技巧
            ans.emplace_back(heap.top().first);
        }
        return ans;
    }
};

class Solution2 {
public:
    void insert(deque<int>& deque, vector<int>& nums, int i, int k){
        int hi = nums[i];
        while(!deque.empty() && nums[deque.back()] < hi)    deque.pop_back();
        deque.push_back(i);
        if(deque.front() + k <= i)  deque.pop_front();
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		//单调队列
		//学会使用C++ STL自带的双向队列结构
        int n = nums.size();
        vector<int> ans;
        deque<int> deque;
        for(int i = 0; i < n; ++i) {
            insert(deque, nums, i, k);
            if(i < k - 1) continue;
            ans.emplace_back(nums[deque.front()]);
        }
        return ans;
    }
};