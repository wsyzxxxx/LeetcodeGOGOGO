class Solution {
private:
    void backTrack(vector<int> & nums, 
                   size_t currentPos, 
                   std::vector<std::vector<int> > & res) {
        if (currentPos == nums.size()) {
            res.push_back(nums);
            return;
        }
        for (size_t i = currentPos; i < nums.size(); i++) {
            std::swap(nums[i], nums[currentPos]);
            backTrack(nums, currentPos + 1, res);
            std::swap(nums[i], nums[currentPos]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        std::vector<std::vector<int> > res;
        backTrack(nums, 0, res);
        return res;
    }
};
