class Solution {
private:
    bool possible(double diff, std::vector<int> & stations, int K) {
        int need = 0;
        for (int i = 1; i < stations.size(); i++) {
            need += (int)(stations[i] - stations[i-1]) / diff;
        }
        
        return need <= K;
    }
public:
    double minmaxGasDist(vector<int>& stations, int k) {
        double lo = 0;
        double hi = 1e8;
        
        while (hi - lo > 1e-6) {
            double mid = (lo + hi) / 2.0;
            if (possible(mid, stations, k)) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
        
        return lo;
    }
};