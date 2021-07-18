class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        
        int count = 0;
        for (int i = 0; i < nums.size()-1; i++) {
            if (nums[i] == 0) {
                continue;
            }
            for (int j = i + 1; j < nums.size(); j++) {
                std::vector<int>::iterator lo = std::upper_bound(nums.begin(), nums.end(), nums[j] - nums[i]);
                std::vector<int>::iterator hi = std::lower_bound(nums.begin(), nums.end(), nums[j] + nums[i]);
                count += hi - lo;
                int lower = lo == nums.end() ? 1001 : *lo;
                int upper = hi == nums.end() ? 1001 : *hi;

                if (nums[i] >= lower && nums[i] < upper) {
                    count--;
                }
                if (nums[j] >= lower && nums[j] < upper) {
                    count--;
                }
                //std::cout << nums[j] << " " << nums[i] << " " << lower << " " << upper << " " << count <<  std::endl;
            }
        }
        
        return count / 3;
    }
};
