class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::set<int> s;
        
        for (const int num : nums) {
            s.insert(num);
        }
        
        int last = -1;
        int currLen = 0;
        int maxLen = 0;
        
        for (const auto & e : s) {
            if (e == last+1) {
                currLen++;
            } else {
                currLen = 1;
            }
            last = e;
            maxLen = std::max(maxLen, currLen);
        }
        
        return maxLen;
    }
};
