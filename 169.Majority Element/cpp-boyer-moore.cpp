class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int candidate = 0;
        
        for (vector<int>::const_iterator consIt = nums.begin();
             consIt != nums.end(); ++consIt) {
            if (count == 0) {
                candidate = *consIt;
            }
            
            count += (*consIt == candidate) ? 1 : -1;
        }
        
        return candidate;
    }
};
