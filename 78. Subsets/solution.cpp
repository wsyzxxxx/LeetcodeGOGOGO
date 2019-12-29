class Solution {
private:
    void findAllSubsets(std::vector<int> & nums,
                        std::vector<std::vector<int> > & res,
                        std::vector<int> currSet,
                        int currIndex) {
        res.push_back(currSet);
        
        for (int i = currIndex; i < nums.size(); i++) {
            currSet.push_back(nums[i]);
            findAllSubsets(nums, res, currSet, i+1);
            currSet.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<std::vector<int> > res;
        //std::sort(nums.begin(), nums.end());
        
        findAllSubsets(nums, res, {}, 0);
        return res;
    }
};
