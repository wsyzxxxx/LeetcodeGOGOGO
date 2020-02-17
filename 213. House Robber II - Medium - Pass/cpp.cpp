class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        
        int rob = 0;
        int nonrob = 0;
        int maxSum = 0;
        for (int i = 1; i < nums.size(); i++) {
            int prerob = rob;
            rob = nonrob + nums[i];
            nonrob = std::max(nonrob, prerob);
        }
        
        maxSum = std::max(rob, nonrob);
        rob = 0;
        nonrob = 0;
        for (int i = 0; i < nums.size()-1; i++) {
            int prerob = rob;
            rob = nonrob + nums[i];
            nonrob = std::max(nonrob, prerob);
        }
        
        maxSum = std::max(maxSum, std::max(rob, nonrob));
        
        return maxSum;
    }
};
