class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end());
        std::vector<std::vector<int>> result;
        result.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] > result.back()[1]) {
                result.push_back(intervals[i]);
            } else {
                result.back()[1] = std::max(intervals[i][1], result.back()[1]);
            }
        }
        
        return result;
    }
};