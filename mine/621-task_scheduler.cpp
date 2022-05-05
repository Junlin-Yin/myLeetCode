class Solution {
public:

    struct WaitingQueue{
        queue<int> q;
        int num;
        WaitingQueue(int n) : num(0) {
            for(int i = 0; i < n; ++i)  q.push(-1);
        }
        void push(int ele) {
            if(ele > 0){
                q.push(ele);
                ++num;
            }else{
                q.push(-1);
            }
        }
        int pop(void) {
            int ele = q.front();
            if(ele != -1)   --num;
            q.pop();
            return ele;
        }
        bool empty(void) {
            return num == 0;
        }
    };

    int leastInterval(vector<char>& tasks, int n) {
        vector<int> t(26, 0);
        for(const char& c: tasks)   ++t[c - 'A'];
        priority_queue<int> heap;
        for(const int& i: t){
            if(i > 0)   heap.push(i);
        }
        WaitingQueue q(n);
        int s = 0, ele;
        while(!heap.empty() || !q.empty()){
            if(!heap.empty()){
                ele = heap.top(); heap.pop();
                q.push(ele - 1);
            }else{
                q.push(-1);
            }
            ele = q.pop();
            if(ele != -1)   heap.push(ele);
            ++s;
        }
        return s;
    }
};