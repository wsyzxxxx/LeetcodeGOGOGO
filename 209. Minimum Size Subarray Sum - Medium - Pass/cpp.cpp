class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minSize = 0;
        int sum = 0;
        int left = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum < target) {
                continue;
            }
            
            while (left < i && sum - nums[left] >= target) {
                sum -= nums[left++];
            }
            
            if (minSize == 0) {
                minSize = i - left + 1;
            } else {
                minSize = std::min(minSize, i - left + 1);
            }
        }
        
        return minSize;
    }
};