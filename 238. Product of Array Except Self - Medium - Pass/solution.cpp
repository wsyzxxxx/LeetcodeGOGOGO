class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> res;
        if (nums.empty()) {
            return res;
        }
        res.push_back(1);
        for (int i = 1; i < nums.size(); i++) {
            res.push_back(res[i-1] * nums[i-1]);
        }
        int r = 1;
        for (int i = nums.size()-1; i >= 0; i--) {
            res[i] = res[i] * r;
            r *= nums[i];
        }
        
        return res;
    }
};
