class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        
        int restIndex = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[restIndex] != nums[i]) {
                nums[++restIndex] = nums[i];
            }
        }
        
        return restIndex+1;
    }
};
