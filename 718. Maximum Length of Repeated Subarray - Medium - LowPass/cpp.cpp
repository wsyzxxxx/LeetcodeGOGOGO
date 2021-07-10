int dp[1005];

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        std::memset(dp, 0, sizeof(dp));
        
        int maxLen = 0;
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = nums2.size()-1; j >= 0; j--) {
                if (nums1[i] == nums2[j]) {
                    dp[j+1] = dp[j] + 1;
                    maxLen = std::max(maxLen, dp[j+1]);
                } else {
                    dp[j+1] = 0;
                }
                //std::cout << i << " " << j << " " << dp[i+1][j+1] << std::endl;
            }
        }
        
        return maxLen;
    }
};