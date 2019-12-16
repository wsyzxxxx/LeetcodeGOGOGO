class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = INT_MIN;
        int maxSum = INT_MIN;
        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[i] < 0) {
                maxSum = max(currSum, maxSum);
            }
            if (currSum < 0) {
                currSum = nums[i];
            } else {
                currSum += nums[i];
            }
        }
        maxSum = max(currSum, maxSum);
        
        return maxSum;
    }
};
