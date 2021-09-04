class Solution {
    private int findMinLinear(int[] nums, int start, int end) {
        int min = nums[start];
        for (int i = start+1; i <= end; i++) {
            min = Math.min(nums[i], min);
        }
        
        return min;
    }
    public int findMin(int[] nums) {
        if (nums[nums.length-1] > nums[0]) {
            return nums[0];
        }
        int start = 0;
        int end = nums.length - 1;
        
        while (start < end) {
            if (start == end-1) {
                break;
            }
            int mid = (start + end) / 2;
            
            if (nums[start] < nums[mid] || nums[end] < nums[mid]) {
                start = mid;
            } else if (nums[end] > nums[mid] || nums[start] > nums[mid]) {
                end = mid;
            } else {
                return findMinLinear(nums, start, end);
            }
        }
        
        return Math.min(nums[start], nums[end]);
    }
}