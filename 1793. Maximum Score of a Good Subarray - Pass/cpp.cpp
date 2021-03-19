class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        std::vector<int> nextMin(nums.size());
        std::vector<int> lastMin(nums.size());
        
        lastMin[k] = nums[k];
        for (int i = k+1; i < nums.size(); i++) {
            lastMin[i] = std::min(nums[i], lastMin[i-1]);
        }
        
        nextMin[k]= nums[k];
        for (int i = k-1; i >= 0; i--) {
            nextMin[i] = std::min(nums[i], nextMin[i+1]);
        }
        
        int start = 0;
        int end = nums.size() - 1;
        int currMin = std::min(lastMin[end], nextMin[start]);
        long long maxScore = (long long)currMin * nums.size();
        while (start <= k && end >= k) {
            if (currMin == nextMin[start]) {
                while (start <= k && nextMin[start] <= currMin) {
                    start++;
                }
            }
            if (currMin == lastMin[end]) {
                while (end >= k && lastMin[end] <= currMin) {
                    end--;
                }
            }
            if (start <= k && end >= k) {
                currMin = std::min(nextMin[start], lastMin[end]);
                maxScore = std::max(maxScore, (long long)currMin * (end - start + 1));
            }
        }
        
        return maxScore;
    }
};