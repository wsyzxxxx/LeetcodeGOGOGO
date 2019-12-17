class Solution {
    int findLinear(std::vector<int> & nums, int start, int end) {
        int min = nums[start];
        for (int i = start + 1; i <= end; i++) {
            if (nums[i] < min) {
                min = nums[i];
            }
        }
        return min;
    }
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        int mid = 0;

        while (nums[start] >= nums[end]) {
            if (end - start <= 1) {
                mid = end;
                break;
            }

            mid = (start + end) / 2;
            if (nums[start] == nums[mid] && nums[mid] == nums[end]) {
                return findLinear(nums, start, end);
            }
            if (nums[mid] >= nums[start]) {
                start = mid;
            } else if (nums[mid] <= nums[end]) {
                end = mid;
            }
        }

        return nums[mid];
    }
};


