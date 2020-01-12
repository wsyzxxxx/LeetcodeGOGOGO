class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<int> res;
        if (nums.size() < 2) {
            return res;
        }
        
        std::unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            std::unordered_map<int, int>::iterator it = mp.find(target - nums[i]);
            if (it != mp.end()) {
                res.push_back(it->second);
                res.push_back(i);
                break;
            } else {
                mp[nums[i]] = i;
            }
        }
        
        return res;
    }
};
