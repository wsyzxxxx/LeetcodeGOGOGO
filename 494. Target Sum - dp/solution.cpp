class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if (nums.empty() || S > 1000 || S < -1000) {
            return 0;
        }
        
        
        int dp[2002][2];
        for (int i = 0; i < 2002; i++) {
            dp[i][0] = 0;
            dp[i][1] = 0;
        }
        
        dp[1000+nums[0]][0] = 1;
        dp[1000-nums[0]][0] += 1;
        int currLevel = 0;
        int currMin = 1000 - nums[0];
        int currMax = 1000 + nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            currLevel = 1 - currLevel;
            for (int j = currMin-nums[i]; j <= currMax+nums[i]; j++) {
                dp[j][currLevel] = 0;
            }
            for (int j = currMin; j <= currMax; j++) {
                dp[j-nums[i]][currLevel] += dp[j][1-currLevel];
                dp[j+nums[i]][currLevel] += dp[j][1-currLevel];
            }
            currMin -= nums[i];
            currMax += nums[i];
        }
        
        return dp[1000+S][currLevel];
    }
};
