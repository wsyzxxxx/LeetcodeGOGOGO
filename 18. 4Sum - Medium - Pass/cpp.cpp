class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        std::vector<std::vector<int> > res;
        if (nums.size() < 4) {
            return res;
        }
        
        std::sort(nums.begin(), nums.end());
        
        //std::cout << "begin" << std::endl;
        int n = nums.size();
        for (int i = 0; i < n-3; ) {
            for (int j = i+1; j < n-2; ) {
                int k = j+1;
                int l = n-1;
                while (k < l) {
                    int currSum = nums[i] + nums[j] + nums[k] + nums[l];
                    //std::cout << currSum << std::endl;
                    if (currSum == target) {
                        res.push_back({nums[i], nums[j], nums[k], nums[l]});
                        while (++k < l && nums[k] == nums[k-1]);
                        while (--l > k && nums[l] == nums[l+1]);
                    } else if (currSum < target) {
                        k++;
                    } else {
                        l--;
                    }
                }
                while (++j < n-2 && nums[j] == nums[j-1]);
            }
            while (++i < n-3 && nums[i] == nums[i-1]);
        }
        
        return res;
    }
};
