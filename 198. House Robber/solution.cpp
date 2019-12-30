class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        
        int pre = 0;
        int curr = 0;
        for (int i = 0; i < nums.size(); i++) {
            int temp = std::max(pre + nums[i], curr);
            pre = curr;
            curr = temp;
        }
        
        return curr;
    }
};