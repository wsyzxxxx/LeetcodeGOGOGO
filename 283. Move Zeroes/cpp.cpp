class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        size_t index = 0;
        size_t currIndex = 0;
        while (index < nums.size()) {
            while (index < nums.size() && nums[index] == 0) {
                index++;
            }
            if (index < nums.size()) {
                nums[currIndex++] = nums[index++];
            }
        }
        
        while (currIndex < nums.size()) {
            nums[currIndex++] = 0;
        }
    }
};
