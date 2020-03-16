class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 1;
        }
        
        for (int i = 0; i < n; i++) {
            while (nums[i] != i+1 && nums[i] > 0 && nums[i] <= n && nums[nums[i]-1] != nums[i]) {
                std::swap(nums[i], nums[nums[i]-1]);
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (nums[i] != i+1) {
                return i+1;
            }
        }
        
        return n+1;
    }
};
