bool cmp(const std::vector<int> & a, const std::vector<int> & b) {
    if (a[0] == b[0]) {
        return a[1] < b[1];
    } else {
        return a[0] < b[0];
    }
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::vector<std::vector<int> > res;
        if (intervals.empty()) {
            return res;
        }
        
        std::sort(intervals.begin(), intervals.end(), cmp);
        
        int start = intervals[0][0];
        int end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] > end) {
                res.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            } else if (intervals[i][1] > end) {
                end = intervals[i][1];
            }
        }
        res.push_back({start, end});
        
        return res;
    }
};
