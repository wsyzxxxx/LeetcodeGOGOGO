class Solution {
private:
    std::vector<int> prefixSum;
public:
    Solution(vector<int>& w): prefixSum(std::vector<int>(w.size())) {
        prefixSum[0] = w[0];
        for (int i = 1; i < w.size(); i++) {
            prefixSum[i] = prefixSum[i-1] + w[i];
        }
    }
    
    int pickIndex() {
        int pos = rand() % prefixSum.back();
        return std::upper_bound(prefixSum.begin(), prefixSum.end(), pos) - prefixSum.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */