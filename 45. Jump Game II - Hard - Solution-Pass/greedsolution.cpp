class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }
        
        int nextRange = 0;
        int currRange = 0;
        int index = 0;
        int count = 0;
        while (index < nums.size()-1) {
            if (currRange >= nums.size()-1) {
                break;
            }
            
            while (index <= currRange) {
                nextRange = std::max(nextRange, nums[index] + index);
                index++;
            }
            currRange = nextRange;
            count++;
        }
        
        return count;
    }
};
