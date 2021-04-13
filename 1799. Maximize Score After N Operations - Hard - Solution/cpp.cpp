const int MAX_RANGE = 1 << 14;
int dp[MAX_RANGE];

int getGCD(int a, int b) {
    if (b == 0) {
        return a;
    }
    return getGCD(b, a % b);
}

int countOne(int bit) {
    int count = 0;
    while (bit) {
        count++;
        bit &= bit-1;
    }
    return count;
}

class Solution {
public:
    int maxScore(vector<int>& nums) {
        std::memset(dp, 0, sizeof(dp));
        int n = nums.size() / 2;
        int upperBound = 1 << nums.size();
        
        for (int last = 0; last < upperBound; last++) {
            for (int i = 0; i < nums.size()-1; i++) {
                if ((last & (1 << i)) == 0) {
                    for (int j = i + 1; j < nums.size(); j++) {
                        if ((last & (1 << j)) == 0) {
                            int curr = (1 << i) | (1 << j);
                            curr = curr | last;
                            int level = countOne(curr) / 2;
                            dp[curr] = std::max(dp[curr], dp[last] + level * getGCD(nums[i], nums[j]));
                            //std::cout << level << " " << dp[curr] << std::endl;
                        }
                    }
                }
            }
        }
        
        return dp[upperBound-1];
    }
};