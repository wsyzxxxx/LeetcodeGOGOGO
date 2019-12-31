class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        
        int maxValue = nums[0];
        int maxPos = nums[0];
        int minNeg = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int temp = maxPos;
            maxPos = std::max(std::max(maxPos * nums[i], minNeg * nums[i]), nums[i]);
            minNeg = std::min(std::min(temp   * nums[i], minNeg * nums[i]), nums[i]);
            maxValue = std::max(maxPos, maxValue);
        }
        
        return maxValue;
    }
};
