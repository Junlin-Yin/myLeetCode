class MinStack {
private:
    vector<int> stack;
    vector<int> minele;

public:
    MinStack() {
        stack.clear();
        minele.clear();
    }
    
    void push(int val) {
        stack.push_back(val);
        if(minele.empty())  minele.push_back(val);
        else                minele.push_back(min(minele.back(), val));
    }
    
    void pop() {
        stack.pop_back();
        minele.pop_back();
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return minele.back();
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