class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        std::vector<int> dp;
        
        for (int i = 0; i < nums.size(); i++) {
            std::vector<int>::iterator it = std::lower_bound(dp.begin(), dp.end(), nums[i]);
            if (it == dp.end()) {
                dp.push_back(nums[i]);
            } else {
                *it = nums[i];
            }
        }
        
        return dp.size();
    }
};