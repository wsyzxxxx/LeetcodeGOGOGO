class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        std::sort(points.begin(), points.end(), [](const std::vector<int>& pa, const std::vector<int>& pb) {
            return pa[0] * pa[0] + pa[1] * pa[1] < pb[0] * pb[0] + pb[1] * pb[1];
        });
        
        return std::vector<std::vector<int>>(points.begin(), points.begin()+k);
    }
};