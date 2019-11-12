class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size() - 2;
        vector<vector<int> > res;
        for (int i = 0; i < n; ) {
            int j = i + 1;
            int k = n + 1;
            while (j < k) {
                int sum = nums[j] + nums[k] + nums[i];
                if (sum == 0) {
                    res.push_back({nums[j], nums[k], nums[i]});
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j-1]) j++;
                    while (k > j && nums[k] == nums[k+1]) k--;
                } else if (sum < 0) {
                    j++;
                } else {
                    k--;
                }
            }
            i++;
            while (i < n && nums[i] == nums[i-1]) i++;
        }
        return res;
    }
};
