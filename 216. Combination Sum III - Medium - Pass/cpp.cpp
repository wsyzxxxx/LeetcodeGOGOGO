class Solution {
private:
    void findCombinations(std::vector<std::vector<int> > & res,
                          std::vector<int> & curr,
                          int index,
                          int currSum,
                          int n,
                          int k) {
        if (curr.size() == k && currSum == n) {
            res.push_back(curr);
            return;
        }
        if (curr.size() >= k) {
            return;
        }
        
        for (int i = index; i <= 9; i++) {
            curr.push_back(i);
            currSum += i;
            
            findCombinations(res, curr, i+1, currSum, n, k);
            
            curr.pop_back();
            currSum -= i;
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        std::vector<std::vector<int> > res;
        if (k < 1 || n < 1 || n < k) {
            return res;
        }
        
        std::vector<int> curr;
        findCombinations(res, curr, 1, 0, n, k);
        
        return res;
    }
};
