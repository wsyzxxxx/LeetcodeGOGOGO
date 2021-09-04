class Solution {

    private int findStart(int[] nums) {
        int start = 0;
        int end = nums.length;
        
        while (start < end-1) {
            int mid = (start + end) / 2;
            
            if (nums[mid] < nums[start]) {
                end = mid;
            } else {
                start = mid;
            }
        }
        
        return end == nums.length ? 0 : end;
    }
    
    public int search(int[] nums, int target) {
        int start = 0;
        int end = nums.length - 1;
        int rotation = findStart(nums);
        
        while (start < end) {
            int mid = (start + end) / 2;
            int realMid = (mid + rotation) % nums.length;
            
            if (nums[realMid] > target) {
                end = mid - 1;
            } else if (nums[realMid] < target) {
                start = mid + 1;
            } else {
                start = mid;
                break;
            }
        }
        
        int realStart = (start + rotation) % nums.length;
        
        return nums[realStart] == target ? realStart : -1;
    }
}