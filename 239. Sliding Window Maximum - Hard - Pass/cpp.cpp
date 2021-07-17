class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::deque<int> dq;
        
        for (int i = 0; i < k; i++) {
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        
        std::vector<int> result = std::vector<int>(nums.size() - k + 1);
        result[0] = nums[dq.front()];
        for (int i = k, j = 1; i < nums.size(); i++, j++) {
            while (!dq.empty() && i - dq.front() >= k) {
                dq.pop_front();
            }
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            result[j] = nums[dq.front()];
        }
        
        return result;
    }
};
