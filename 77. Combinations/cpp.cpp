class Solution {
private:
    void generateCombinations(std::vector<std::vector<int> > & res,
                              std::vector<int> & currSet,
                              int start,
                              int n,
                              int k) {
        if (currSet.size() == k) {
            res.push_back(currSet);
            return;
        } else if (n - start + currSet.size() + 1 < k) {
            return;
        }

        for (int i = start; i <= n; i++) {
            currSet.push_back(i);
            generateCombinations(res, currSet, i+1, n, k);
            currSet.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        std::vector<std::vector<int> > res;
        if (n <= 0 || k <= 0 || k > n) {
            return res;
        } 

        std::vector<int> currSet;
        generateCombinations(res, currSet, 1, n, k);

        return res;
    }
};