class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        std::vector<int> res;
        if (nums1.empty() || nums2.empty()) {
            return res;
        }
        
        std::unordered_map<int, int> mp;
        std::stack<int> s;
        for (const auto num : nums2) {
            while (!s.empty() && s.top() < num) {
                mp[s.top()] = num;
                s.pop();
            }
            s.push(num);
        }
        
        for (const auto num : nums1) {
            if (mp.find(num) != mp.end()) {
                res.push_back(mp[num]);
            } else {
                res.push_back(-1);
            }
        }
        
        return res;
    }
};
