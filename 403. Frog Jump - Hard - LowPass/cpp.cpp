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
        
        std::unordered_map<int, int> mp;
        for (int i = 0; i < stones.size(); i++) {
            mp[stones[i]] = i;
        }
        
        bool dp[n+1][n+1] = {false};
        dp[1][0] = true;
        
        for (int i = 1; i < stones.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (dp[i][j]) {
                    int k = stones[i] - stones[j];
                    int curr = stones[i];
                    if (mp.find(curr+k-1) != mp.end()) {
                        dp[mp[curr+k-1]][i] = true;
                    }
                    if (mp.find(curr+k) != mp.end()) {
                        dp[mp[curr+k]][i] = true;
                    }
                    if (mp.find(curr+k+1) != mp.end()) {
                        dp[mp[curr+k+1]][i] = true;
                    }
                    if (curr+k-1 <= dest && curr+k+1 >= dest) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};
