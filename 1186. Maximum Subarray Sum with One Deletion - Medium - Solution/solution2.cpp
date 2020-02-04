// class Solution {
// public:
//     int maximumSum(vector<int>& arr) {
//         if (arr.empty()) {
//             return 0;
//         }
//         if (arr.size() == 1) {
//             return arr[0];
//         }
        
//         int deletedSum = std::max(arr[0], arr[1]);
//         int nonDeletedSum = std::max(arr[0] + arr[1], arr[1]);
//         int res = std::max(deletedSum, nonDeletedSum);
        
//         for (int i = 2; i < arr.size(); i++) {
//             deletedSum = std::max(nonDeletedSum, deletedSum + arr[i]);
//             nonDeletedSum = std::max(nonDeletedSum + arr[i], arr[i]);
//             res = std::max(res, std::max(deletedSum, nonDeletedSum));
//         }
        
//         return res;
//     }
// };

class Solution {
public:
    int maximumSum(vector<int>& arr) {
        if (arr.empty()) {
            return 0;
        }
        if (arr.size() == 1) {
            return arr[0];
        }
        
//         int deletedSum = std::max(arr[0], arr[1]);
//         int nonDeletedSum = std::max(arr[0] + arr[1], arr[1]);
//         int res = std::max(deletedSum, nonDeletedSum);
        
//         for (int i = 2; i < arr.size(); i++) {
//             deletedSum = std::max(nonDeletedSum, deletedSum + arr[i]);
//             nonDeletedSum = std::max(nonDeletedSum + arr[i], arr[i]);
//             res = std::max(res, std::max(deletedSum, nonDeletedSum));
//         }
        
        std::vector<int> leftMax(arr.size(), 0);
        int currSum = 0;
        int maxSum = std::numeric_limits<int>::min();
        for (int i = 0; i < arr.size(); i++) {
            currSum += arr[i];
            maxSum = std::max(maxSum, currSum);
            leftMax[i] = currSum;
            if (currSum < 0) {
                currSum = 0;
            }
        }
        
        std::vector<int> rightMax(arr.size(), 0);
        currSum = 0;
        int rightMaxSum = std::numeric_limits<int>::min();
        for (int i = arr.size()-1; i >= 0; i--) {
            currSum += arr[i];
            rightMaxSum = std::max(rightMaxSum, currSum);
            maxSum = std::max(maxSum, rightMaxSum);
            rightMax[i] = currSum;
            if (currSum < 0) {
                currSum = 0;
            }
        }
        //1 -1 -2 3
        //0 -1  1 3
        std::cout << maxSum << std::endl;
        for (int i = 1; i < arr.size()-1; i++) {
            maxSum = std::max(maxSum, leftMax[i-1] + rightMax[i+1]);
        }
        return maxSum;
    }
};
