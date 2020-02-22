class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) {
            return false;
        }
        
        std::vector<int> leftMin(n);
        leftMin[0] = nums[0];
        for (int i = 1; i < n; i++) {
            leftMin[i] = std::min(leftMin[i-1], nums[i]);
        }

        std::stack<int> s;
        for (int i = n-1; i >= 0; i--) {
            while (!s.empty() && nums[s.top()] <= leftMin[i]) {
                s.pop();
            }
            if (!s.empty() && nums[s.top()] < nums[i]) {
                return true;
            }
            s.push(i);
        }
        
        return false;
    }
};
