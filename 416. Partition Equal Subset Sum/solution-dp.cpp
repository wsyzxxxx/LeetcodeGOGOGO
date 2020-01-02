class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if (nums.empty()) {
            return false;
        }
        
        int sum = 0;
        for (const int num : nums) {
            sum += num;
        }
        if (sum & 1) {
            return false;
        }
        sum >>= 1;
        
        bool dp[sum+1] = {false};
        dp[0] = true;
        for (const int num : nums) {
            for (int j = sum; j >= num; j--) {
                dp[j] = dp[j] || dp[j-num];
            }
            if (dp[sum]) {
                return true;
            }
        }
        
        return dp[sum];
                
    }
};
