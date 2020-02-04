class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int res = 0;
        if (nums.empty() || target < 1) {
            return res;
        }

        std::vector<long> dp(target + 1, 0);
        dp[0] = 1;
        
        std::sort(nums.begin(), nums.end());
        for (int i = 1; i <= target; i++) {
            for (const auto num : nums) {
                if (num <= i) {
                    dp[i] = (dp[i] + dp[i - num]) % 2147483647;
                } else {
                    break;
                }
            }
        }
        
        return dp[target];
    }
};
