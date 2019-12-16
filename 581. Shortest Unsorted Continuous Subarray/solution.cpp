class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        
        int begin, end;
        int maxNum, minNum;
        size_t size = nums.size();
        
        begin = -1;
        end = -2;
        minNum = nums[size-1];
        maxNum = nums[0];
        for (size_t i = 1; i < nums.size(); i++) {
            minNum = std::min(nums[size-1-i], minNum);
            maxNum = std::max(nums[i], maxNum);
            if (nums[i] < maxNum) {
                end = i;
            }
            if (nums[size-1-i] > minNum) {
                begin = size-1-i;
            }
        }
        
        return end - begin + 1;
    }
};
