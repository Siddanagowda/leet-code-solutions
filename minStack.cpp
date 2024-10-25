class MinStack {
private:
    stack<int> s; // Main stack to store elements
    stack<int> min; 
public:
    MinStack() {
    }
    
    void push(int val) {
        s.push(val);
        if(min.empty()||val<=min.top()){
            min.push(val);
        }
    }
    
    void pop() {
        int pop=s.top();
        s.pop();
        if(pop==min.top()){
            min.pop();
        }
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min.top();
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