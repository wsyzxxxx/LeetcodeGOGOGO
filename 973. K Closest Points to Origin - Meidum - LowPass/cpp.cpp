class Compare { 
public:
    bool operator()(const std::vector<int> & a, const std::vector<int> & b) {
    return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        if (points.empty() || points.size() <= K) {
            return points;
        }
        if (K <= 0) {
            return {};
        }
        
        std::priority_queue<std::vector<int>, std::vector<std::vector<int> >, Compare> pq;
        std::vector<std::vector<int> > res;
        for (int i = 0; i < K; i++) {
            pq.push(points[i]);
        }
        //std::sort(points.begin(), points.end(), cmp);
        
        for (int i = points.size()-1; i >= K; i--) {
            pq.push(points[i]);
            pq.pop();
        }
        
        while (!pq.empty()) {
            res.push_back(pq.top());
            pq.pop();
        }
        
        return res;
    }
};
