class MinStack {
private:
    vector<long long> diff_stack;
    long long minele;

public:
    MinStack() : minele(INT_MAX) {
        diff_stack.clear();
    }
    
    void push(int val) {
        long long diff = val - minele;
        if(diff < 0)    minele = val;
        diff_stack.push_back(diff);
    }
    
    void pop() {
        long long diff = diff_stack.back();
        if(diff < 0)    minele -= diff;
        diff_stack.pop_back();
    }
    
    int top() {
        long long diff = diff_stack.back();
        return diff < 0 ? minele : minele + diff;
    }
    
    int getMin() {
        return minele;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */