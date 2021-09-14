class MyCalendarThree {
private:
    std::map<int, int> timeline;
public:
    MyCalendarThree() {
        timeline.clear();
    }
    
    int book(int start, int end) {
        timeline[start]++;
        timeline[end]--;
        
        int curr = 0;
        int currMax = 0;
        for (const auto & kv : timeline) {
            curr += kv.second;
            currMax = std::max(currMax, curr);
        }
        return currMax;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */