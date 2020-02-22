class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> res(n, -1);
        if (n == 0) {
            return res;
        }
        
        std::stack<std::pair<int, int> > s;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && s.top().second < nums[i]) {
                res[s.top().first] = nums[i];
                s.pop();
            }
            s.push(std::make_pair(i, nums[i]));
        }
        
        int i = 0;
        while (!s.empty() && i < s.top().first) {
            if (nums[i] > s.top().second) {
                res[s.top().first] = nums[i];
                s.pop();
            } else {
                i++;
            }
        }
        
        return res;
    }
};
