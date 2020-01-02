class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if (nums.empty()) {
            return false;
        }
        
        int sum = 0;
        for (const int num : nums) {
            sum += num;
        }
        if (sum & 1) {
            return false;
        }
        
        std::bitset<50001> bits(1);
        sum >>= 1;
        for (const int num : nums) {
            bits |= bits << num;
            if (bits[sum]) {
                return true;
            }
        }
        
        return false;
                
    }
};
