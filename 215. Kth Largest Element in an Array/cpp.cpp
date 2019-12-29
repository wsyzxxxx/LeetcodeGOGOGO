bool isValid = true;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.empty()) {
            isValid = false;
            return 0;
        }
        
        std::priority_queue<int, std::vector<int>, std::greater<int> > pq;
        
        for (int i = 0; i < nums.size(); i++) {
            if (pq.size() < k) {
                pq.push(nums[i]);
            } else {
                if (nums[i] > pq.top()) {
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
        }
        
        return pq.top();
    }
};
