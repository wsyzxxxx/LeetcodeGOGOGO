class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> result;
        
        for (int i = 0; i < (int)nums.size()-2;) {
            int j = i + 1;
            int k = nums.size()-1;
            
            while (j < k) {
                if (nums[i] + nums[j] + nums[k] > 0) {
                    k--;
                } else if (nums[i] + nums[j] + nums[k] < 0) {
                    j++;
                } else {
                    result.push_back({nums[i], nums[j], nums[k]});
                    while (++j < k && nums[j] == nums[j-1]);
                    while (--k > j && nums[k] == nums[k+1]);
                }
            }
            while (++i < nums.size()-2 && nums[i] == nums[i-1]);
        }
        
        return result;
    }
};