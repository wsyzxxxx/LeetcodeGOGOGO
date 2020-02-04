class Solution {
private:
    void findAllPerms(std::vector<std::vector<int> > & res,
                      std::vector<int> & nums,
                      //int currIndex,
                      std::vector<bool> & isVisited,
                      std::vector<int> & currSet) {
        if (currSet.size() == nums.size()) {
            res.push_back(currSet);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!isVisited[i]) {
                isVisited[i] = true;
                currSet.push_back(nums[i]);
                findAllPerms(res, nums, isVisited, currSet);
                currSet.pop_back();
                isVisited[i] = false;
                while (i < nums.size()-1 && nums[i] == nums[i+1]) {
                    i++;
                }
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        std::vector<std::vector<int> > res;
        if (nums.empty()) {
            return res;
        }

        std::sort(nums.begin(), nums.end());
        std::vector<bool> isVisited(nums.size(), false);
        std::vector<int> currSet;
        findAllPerms(res, nums, isVisited, currSet);

        return res;
    }
};