class MyStack {
private:
    std::queue<int> queue1;
    std::queue<int> queue2;
    
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        if (queue1.empty()) {
            queue2.push(x);
        } else {
            queue1.push(x);
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int res;
        if (queue1.empty()) {
            while (queue2.size() > 1) {
                queue1.push(queue2.front());
                queue2.pop();
            }
            res = queue2.front();
            queue2.pop();
            
        } else {
            while (queue1.size() > 1) {
                queue2.push(queue1.front());
                queue1.pop();
            }
            res = queue1.front();
            queue1.pop();
        }
        
        return res;
    }
    
    /** Get the top element. */
    int top() {
        int res = pop();
        if (queue1.empty()) {
            queue2.push(res);
        } else {
            queue1.push(res);
        }
        
        return res;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return (queue1.empty() && queue2.empty());
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
