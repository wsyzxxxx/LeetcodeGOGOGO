class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if (array.empty()) {
            return 0;
        }
        
        int maxSum = INT_MIN;
        int currMaxSum = 0;
        for (int i = 0; i < array.size(); i++) {
            if (currMaxSum < 0) {
                currMaxSum = array[i];
            } else {
                currMaxSum += array[i];
            }
            
            if (currMaxSum > maxSum) {
                maxSum = currMaxSum;
            }
        }
        
        return maxSum;
    }
};
