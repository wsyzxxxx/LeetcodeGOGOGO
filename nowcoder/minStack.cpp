class Solution {
private:
    std::stack<int> s1;
    std::stack<int> s2;
public:
    void push(int value) {
        s1.push(value);
        
        if (s2.empty() || value < s2.top()) {
            s2.push(value);
        } else {
            s2.push(s2.top());
        }
    }
    void pop() {
        s1.pop();
        s2.pop();
    }
    int top() {
        return s1.top();
    }
    int min() {
        return s2.top();
    }
};
