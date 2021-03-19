#define MAX_LEN 1005

int dp[MAX_LEN][2];

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        
        std::memset(dp, 0, sizeof(dp));
        
        dp[0][0] = 1;
        dp[0][1] = 1;
        int result = 1;
        
        std::stack<int> minS, maxS;
        minS.push(0);
        maxS.push(0);
        for (int i = 1; i < nums.size(); i++) {
            dp[i][0] = 1;
            dp[i][1] = 1;
            while (!minS.empty() && nums[minS.top()] < nums[i]) {
                dp[i][1] = std::max(dp[i][1], dp[minS.top()][0] + 1);
                minS.pop();
            }
            if (!minS.empty()) {
                dp[i][0] = std::max(dp[i][0], dp[minS.top()][0]);
            }
            minS.push(i);
            while (!maxS.empty() && nums[maxS.top()] > nums[i]) {
                dp[i][0] = std::max(dp[i][0], dp[maxS.top()][1] + 1);
                maxS.pop();
            }
            if (!maxS.empty()) {
                dp[i][1] = std::max(dp[i][1], dp[maxS.top()][1]);
            }
            maxS.push(i);
            
            result = std::max(result, std::max(dp[i][0], dp[i][1]));
        }
        
//         for (int i = 1; i < nums.size(); i++) {
//             dp[i][0] = dp[i][1] = 1;
//             for (int j = i-1; j >= 0; j--) {
//                 if (nums[j] < nums[i]) {
//                     dp[i][1] = std::max(dp[i][1], dp[j][0] + 1);
//                 } else if (nums[j] > nums[i]) {
//                     dp[i][0] = std::max(dp[i][0], dp[j][1] + 1);
//                 }
//             }
            
//             std::cout << i << " " << dp[i][0] << " " << dp[i][1] << std::endl;
//             result = std::max(result, std::max(dp[i][0], dp[i][1]));
//         }
        
        return result;
    }
};