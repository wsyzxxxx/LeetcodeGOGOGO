class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size() - 2;
        //vector<int> res;
        int currDist = INT_MAX;
        int res = 0;
        for (int i = 0; i < n; ) {
            int j = i + 1;
            int k = n + 1;
            while (j < k) {
                int currValue = nums[i] + nums[j] + nums[k];
                if (currValue < target) {
                    int tmpDist = target - currValue;
                    if (tmpDist < currDist) {
                        res = currValue;
                        currDist = tmpDist;
                    }
                    j++;
                } else {
                    int tmpDist = currValue - target;
                    if (tmpDist < currDist) {
                        res = currValue;
                        currDist = tmpDist;
                    }
                    k--;
                }
            }
            //i++;
            while (++i < n && nums[i] == nums[i-1]) {
                //i++;
            }
        }
        //return res;
        return res;
    }
};
