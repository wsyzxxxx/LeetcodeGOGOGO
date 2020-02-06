class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.empty()) {
            return false;
        }
        
        int canJump = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] + i >= nums.size() - 1) {
                return true;
            }
            canJump = std::max(canJump, nums[i]);
            canJump--;
            if (canJump < 0) {
                break;
            }
        }
        
        return false;
    }
};
