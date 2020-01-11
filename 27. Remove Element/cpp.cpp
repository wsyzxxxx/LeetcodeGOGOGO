class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int restIndex = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == val) {
                continue;
            }
            
            nums[restIndex++] = nums[i];
        }
        
        return restIndex;
    }
};
