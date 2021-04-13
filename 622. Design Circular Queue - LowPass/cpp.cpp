class MyCircularQueue {
private:
    std::vector<int> q;
    int start;
    int end;
public:
    MyCircularQueue(int k): q(std::vector<int>(k+2)) {
        start = 0;
        end = 1;
    }
    
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        q[end++] = value;
        if (end == q.size()) {
            end = 0;
        }
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        ++start;
        if (start == q.size()) {
            start = 0;
        }
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : (start+1 == q.size() ? q[0] : q[start+1]);
    }
    
    int Rear() {
        return isEmpty() ? -1 : (end == 0 ? q.back() : q[end-1]);
    }
    
    bool isEmpty() {
        return (end == start+1 || start == q.size()-1 && end == 0);
    }
    
    bool isFull() {
        return (end+1 == start || end == q.size()-1 && start == 0);
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */