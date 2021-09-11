#define LL long long

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        std::vector<std::unordered_map<LL, LL>> mps(nums.size());
        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                LL diff = (LL)nums[i] - nums[j];
                int prev = 0;
                if (mps[j].find(diff) != mps[j].end()) {
                    prev = mps[j][diff];
                }
                mps[i][diff] += prev + 1;
                result += prev;
            }
        }
        
        return result;
    }
};