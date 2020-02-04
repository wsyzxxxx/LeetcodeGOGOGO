class Solution {
public:
    int maximumSum(vector<int>& arr) {
        if (arr.empty()) {
            return 0;
        }
        if (arr.size() == 1) {
            return arr[0];
        }
        
        int deletedSum = std::max(arr[0], arr[1]);
        int nonDeletedSum = std::max(arr[0] + arr[1], arr[1]);
        int res = std::max(deletedSum, nonDeletedSum);
        
        for (int i = 2; i < arr.size(); i++) {
            deletedSum = std::max(nonDeletedSum, deletedSum + arr[i]);
            nonDeletedSum = std::max(nonDeletedSum + arr[i], arr[i]);
            res = std::max(res, std::max(deletedSum, nonDeletedSum));
        }
        
        return res;
    }
};
