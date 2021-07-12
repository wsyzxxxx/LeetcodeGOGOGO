class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if (nums.empty()) {
            return 0;
        }
        
        std::unordered_map<int, int> sumCount;
        sumCount[0]++;
        int sum = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            count += sumCount[sum - k];
            sumCount[sum]++;
        }
        
        return count;
    }
};
