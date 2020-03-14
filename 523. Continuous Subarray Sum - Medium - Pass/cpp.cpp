class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.empty()) {
            return false;
        }
        
        int sum = 0;
        std::unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int mod = k == 0 ? sum : sum % k;

            if (mod == 0 && i > 0) {
                return true;
            } else if (mp.find(mod) == mp.end()) {
                mp[mod] = i;
            } else if (i - mp[mod] >= 2) {
                return true;
            }
        }
        
        return false;
    }
};
