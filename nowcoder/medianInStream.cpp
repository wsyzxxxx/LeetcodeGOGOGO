class Solution {
private:
    std::priority_queue<int, std::vector<int>, std::less<int> > maxHeap;
    std::priority_queue<int, std::vector<int>, std::greater<int> > minHeap;
public:
    void Insert(int num) {
        if (((maxHeap.size() + minHeap.size()) & 1) == 0) {
            if (minHeap.size() > 0 && num > minHeap.top()) {
                minHeap.push(num);
                num = minHeap.top();
                minHeap.pop();
            }
            
            maxHeap.push(num);
        } else {
            if (maxHeap.size() > 0 && num < maxHeap.top()) {
                maxHeap.push(num);
                num = maxHeap.top();
                maxHeap.pop();
            }
            
            minHeap.push(num);
        }
    }

    double GetMedian() { 
        if (maxHeap.size() + minHeap.size() == 0) {
            return 0.0;
        }
        
        if (((maxHeap.size() + minHeap.size()) & 1) == 0) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        } else {
            return maxHeap.top();
        }
            
    }
};
