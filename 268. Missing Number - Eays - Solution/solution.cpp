class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if (nums.empty()) {
            return -1;
        }
        
        int sum = 0;
        for (int i = 1; i <= nums.size(); i++) {
            sum = sum ^ i;
        }
        
        int sum2 = 0;
        for (const auto num : nums) {
            sum2 = sum2 ^ num;
        }
        
        return sum ^ sum2;
    }
};
