class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) {
            return nums.size();
        }
        
        int restIndex = 1;
        for (int i = 2; i < nums.size(); i++) {
            if (nums[restIndex] != nums[i] || nums[restIndex-1] != nums[i]) {
                nums[++restIndex] = nums[i];
            }
        }
        
        return restIndex+1;
    }
};
