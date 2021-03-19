class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        
        int downTo = 1;
        int upTo = 1;
        
        for (int i = 1; i < nums.size(); i++) {
            int lastDownTo = downTo;
            int lastUpTo = upTo;
            
            if (nums[i] > nums[i-1]) {
                //downTo = lastUpTo;
                upTo = lastDownTo + 1;
            } else if (nums[i] < nums[i-1]) {
                downTo = lastUpTo + 1;
                //upTo = lastDownTo;
            } else {
                downTo = lastDownTo;
                upTo = lastUpTo;
            }
        }
        
        return std::max(downTo, upTo);
    }
};