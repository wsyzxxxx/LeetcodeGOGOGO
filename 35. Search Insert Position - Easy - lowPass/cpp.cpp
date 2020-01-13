class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.empty()) {
            return 0;
        }
        
        int start = 0;
        int end = nums.size() - 1;
        while (start < end) {
            //std::cout << start << " " << end << std::endl;
            int mid = (start + end) / 2;
            if (nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid;
            }
            
        }
        
        if (nums[start] < target) {
            start++;
        }
        return start;
    }
};
