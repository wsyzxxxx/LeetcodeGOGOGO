class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }
        
        std::vector<int> dp(nums.size(), std::numeric_limits<int>::max());
        dp[0] = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] + i >= nums.size() - 1) {
                return dp[i] + 1;
            }
            for (int j = nums[i] + i; j > i; j--) {
                if (dp[j] < dp[i] + 1) {
                    break;
                }
                dp[j] = dp[i] + 1;
            }
        }
        
        return dp[nums.size()-1];
    }
};
