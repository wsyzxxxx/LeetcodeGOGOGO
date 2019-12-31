class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty()) {
            return 0;
        }
        
        std::vector<int> dp = triangle.back();
        
        for (int i = triangle.size() - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                dp[j] = std::min(dp[j], dp[j+1]) + triangle[i][j];
            }
        }
        
        return dp[0];
    }
};
