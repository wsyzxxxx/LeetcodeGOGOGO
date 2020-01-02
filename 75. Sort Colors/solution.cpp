class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.empty()) {
            return;
        }
        
        int zeroPos = 0;
        int twoPos = nums.size() - 1;
        for (int i = 0; i <= twoPos; i++) {
            if (nums[i] == 0 && i != zeroPos) {
                std::swap(nums[i--], nums[zeroPos++]);
            } else if (nums[i] == 2 && i != twoPos) {
                std::swap(nums[i--], nums[twoPos--]);
            }
        }
    }
};
