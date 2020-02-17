bool dp[1102][1102];
class Solution {
public:
    bool canCross(vector<int>& stones) {
        if (stones.size() < 1) {
            return true;
        }
        if (stones[1] != 1) {
            return false;
        }
        
        int n = stones.size();
        int dest = stones.back();
        
        std::memset(dp, 0, sizeof(dp));
        dp[0][1] = true;
        
        for (int i = 1; i < stones.size(); i++) {
            for (int j = 0; j < i; j++) {
                int dist = stones[i] - stones[j];
                if (dist > 0 && dist <= n && dp[j][dist]) {
                    //std::cout << j << " " << std::endl;
                    dp[i][dist] = true;
                    if (dist - 1 > 0) {
                        dp[i][dist-1] = true;
                    }
                    if (dist + 1 <= n) {
                        dp[i][dist+1] = true;
                    }
                    if (i == n-1) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};
