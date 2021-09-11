class Solution {
public:
    int minDifference(vector<int>& nums) {
        if (nums.size() <= 4) {
            return 0;
        }
        
        std::priority_queue<int> maxHeap;
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
        for (int i = 0; i < nums.size(); i++) {
            maxHeap.push(nums[i]);
            if (maxHeap.size() > 4) {
                maxHeap.pop();
            }
            minHeap.push(nums[i]);
            if (minHeap.size() > 4) {
                minHeap.pop();
            }
        }
        std::vector<int> firstFour, lastFour;
        for (int i = 0; i < 4; i++) {
            firstFour.push_back(maxHeap.top());
            maxHeap.pop();
            lastFour.push_back(minHeap.top());
            minHeap.pop();
        }
        
        std::sort(firstFour.begin(), firstFour.end());
        std::sort(lastFour.begin(), lastFour.end(), std::less<int>());
        int minDiff = lastFour[0] - firstFour[0];
        for (int i = 0; i < 4; i++) {
            minDiff = std::min(minDiff, lastFour[i] - firstFour[i]);
        }
        
        return minDiff;
    }
};