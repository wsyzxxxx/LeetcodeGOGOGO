class Solution {
private:
    int findMaxInRange(std::vector<int> &nums, int start, int end) {
        int pre = 0;
        int curr = 0;
        for (int i = start; i < end; i++) {
            int tempMax = std::max(pre + nums[i], curr);
            pre = curr;
            curr = tempMax;
        }

        return curr;
    }
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }

        return std::max(findMaxInRange(nums, 0, nums.size()-1), findMaxInRange(nums, 1, nums.size()));
    }
};