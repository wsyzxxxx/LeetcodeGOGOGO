class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> res(nums.size());
        
        res[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            res[i] = res[i-1] * nums[i];
        }
        
        long long rightProd = 1;
        for (int i = nums.size()-1; i > 0; i--) {
            res[i] = res[i-1] * rightProd;
            rightProd *= nums[i];
        }
        res[0] = rightProd;
        
        return res;
    }
};