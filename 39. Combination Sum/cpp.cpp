class Solution {
private:
    void findAllComb(std::vector<int> & candidates,
                     int target,
                     std::vector<std::vector<int> > & res,
                     std::vector<int> & currSet,
                     int currIndex,
                     int currSum) {
        for (int i = currIndex; i < candidates.size(); ++i) {
            currSum += candidates[i];
            currSet.push_back(candidates[i]);
            
            if (currSum == target) {
                res.push_back(currSet);
            } else if (currSum < target) {
                findAllComb(candidates, target, res, currSet, i, currSum);
            }
            
            currSum -= candidates[i];
            currSet.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        std::vector<std::vector<int> > res;
        if (candidates.empty() || target <= 0) {
            return res;
        }
        
        std::vector<int> currSet;
        findAllComb(candidates, target, res, currSet, 0, 0);
        return res;
    }
};
