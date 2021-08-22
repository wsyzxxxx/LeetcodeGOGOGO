class Solution {
    public int maxSubArrayLen(int[] nums, int k) {
        Map<Long, Integer> sumToIndex = new HashMap<>();
        
        long sum = 0;
        sumToIndex.put(0L, -1);
        
        int maxSize = 0;
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
            
            if (sumToIndex.containsKey(sum - k)) {
                maxSize = Math.max(maxSize, i - sumToIndex.get(sum - k));
            }
            
            if (!sumToIndex.containsKey(sum)) {
                sumToIndex.put(sum, i);
            }
        }
        
        return maxSize;
    }
}