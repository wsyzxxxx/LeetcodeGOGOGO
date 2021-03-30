bool cmp(const std::vector<int> & a, const std::vector<int> & b) {
    return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
}

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        std::sort(envelopes.begin(), envelopes.end(), cmp);
        std::vector<int> dp;
        
        for (int i = 0; i < envelopes.size(); i++) {
            std::vector<int>::iterator it = std::lower_bound(dp.begin(), dp.end(), envelopes[i][1]);
            if (it == dp.end()) {
                dp.push_back(envelopes[i][1]);
            } else {
                *it = envelopes[i][1];
            }
        }
        
        return dp.size();
    }
};