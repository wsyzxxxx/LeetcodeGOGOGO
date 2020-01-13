class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) {
            return {-1, -1};
        }
        
        int low = 0;
        int high = nums.size()-1;
        while (low < high) {
            int mid = (low + high) / 2;
            if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        
        if (nums[low] != target) {
            return {-1, -1};
        }
        
        high = nums.size() - 1;
        int first = low;
        while (low < high) {
            int mid = (low + high) / 2 + 1;
            if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid;
            }
        }
        
        return {first, high};
    }
};
