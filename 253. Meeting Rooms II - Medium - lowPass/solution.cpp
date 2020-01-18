bool cmp(const std::vector<int> & a, const std::vector<int> & b) {
    if (a[0] == b[0]) {
        return a[1] < b[1];
    } else {
        return a[0] < b[0];
    }
}

class Compare {
public:
    bool operator()(const std::vector<int> & lhs, const std::vector<int> & rhs) {
        return lhs[1] > rhs[1];
    }
};
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return 0;
        }
        
        std::vector<int> starts(intervals.size());
        std::vector<int> ends(intervals.size());
        
        for (int i = 0; i < intervals.size(); i++) {
            starts[i] = intervals[i][0];
            ends[i] = intervals[i][1];
        }
        
        std::sort(starts.begin(), starts.end());
        std::sort(ends.begin(), ends.end());
        
        int res = 0;
        int endIndex = 0;
        for (int i = 0; i < starts.size(); i++) {
            if (starts[i] < ends[endIndex]) {
                res++;
            } else {
                endIndex++;
            }
        }
        
        return res;
        
//         std::sort(intervals.begin(), intervals.end(), cmp);
        
//         std::priority_queue<std::vector<int>, std::vector<std::vector<int> >, Compare> pq;
        
//         int res = 0;
//         for (const auto interval : intervals) {
//             while (!pq.empty() && pq.top()[1] <= interval[0]) {
//                 pq.pop();
//             }
//             pq.push(interval);
            
//             if (pq.size() > res) {
//                 res = pq.size();
//             }
//         }
        
//        return res;
    }
};
