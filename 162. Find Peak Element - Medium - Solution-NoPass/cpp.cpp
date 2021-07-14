class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.empty()) {
            return -1;
        }
        
        int low = 0;
        int high = nums.size() - 1;
        
        while (low < high) {
            int mid = (low + high) / 2;
            //std::cout << low << " " << high << std::endl;
            if (mid != nums.size()-1 && nums[mid+1] > nums[mid]) {
                low = mid + 1;
            } else if (mid != 0 && nums[mid-1] > nums[mid]) {
                high = mid;
            } else {
                return mid;
            }
        }
        
        return low;
    }
};
