class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        
        int currSum = -1;
        int maxSum = std::numeric_limits<int>::min();
        for (int i = 0; i < nums.size(); i++) {
            if (currSum < 0) {
                currSum = nums[i];
            } else {
                currSum += nums[i];
            }
            
            if (currSum > maxSum) {
                maxSum = currSum;
            }
        }
        
        return maxSum;
    }
};
