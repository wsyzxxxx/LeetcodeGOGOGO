class Solution {
public:
    int validSubarrays(vector<int>& nums) {
        int n = nums.size();
        
        if (n == 0) {
            return 0;
        }
        
        std::stack<int> s;
        int res = 0;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && s.top() > nums[i]) {
                s.pop();
            }
            s.push(nums[i]);
            res += s.size();
        }
        
        return res;
    }
};
