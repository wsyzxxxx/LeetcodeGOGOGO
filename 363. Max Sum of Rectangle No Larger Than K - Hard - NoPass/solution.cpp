class Solution {
private:
    int maxSum;
    void updateResults(const std::vector<int> & sums, int k) {
        std::set<int> s;
        std::set<int>::iterator it;
        s.insert(0);
        
        int sum = 0;
        for (int i = 0; i < sums.size(); i++) {
            sum += sums[i];
            it = s.lower_bound(sum - k);
            
            if (it != s.end()) {
                maxSum = std::max(maxSum, sum - *it);
            }
            
            s.insert(sum);
        }
    }
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        std::vector<int> sums(matrix[0].size());
        maxSum = INT_MIN;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++){
                sums[j] = 0;
            }
            for (int j = i; j < matrix.size(); j++) {
                for (int k = 0; k < matrix[j].size(); k++) {
                    sums[k] += matrix[j][k];
                }
                
                updateResults(sums, k);
                
                if (maxSum == k) {
                    return k;
                }
            }
        }
        
        return maxSum;
    }
};