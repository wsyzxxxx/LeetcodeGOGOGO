class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        long long sum = 0;
        std::unordered_map<long long, int> mp;
        
        int count = 0;
        mp[0]++;
        for (const int num : nums) {
            sum += num;
            count += mp[sum-k];
            mp[sum]++;
        }
        
        return count;
    }
};