class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int prod = 1;
        int count = 0;
        int i = 0;
        for (; i < nums.size(); i++) {
            if (prod * nums[i] >= k) {
                break;
            }
            
            prod *= nums[i];
            count += i+1;
        }
        
        int left = 0;
        for (; i < nums.size(); i++) {
            prod *= nums[i];
            while (prod >= k && left < i) {
                prod /= nums[left++];
            }
            
            if (prod < k) {
                count += i - left + 1;
            }
        }
        
        return count;
    }
};