class Solution {
private:
    std::vector<int> & nums;
public:
    Solution(vector<int>& nums) : nums(nums) {}
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        std::vector<int> res(nums);
        for (int i = 0; i < res.size(); i++) {
            int pos = rand() % (res.size() - i);
            std::swap(res[i+pos], res[i]);
        }
        
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
