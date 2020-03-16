struct Worker {
    int speed;
    int eff;
};

std::vector<Worker> workers;

bool cmp(const Worker & a, const Worker & b) {
    return a.eff > b.eff;
}

class Solution {
private:
    int mod = 1e9 + 7;
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        if (n <= 0 || speed.empty() || efficiency.empty() || k <= 0 || k > n) {
            return 0;
        }
        workers.clear();
        
        for (int i = 0; i < n; i++) {
            workers.push_back(Worker{speed[i], efficiency[i]});
        }
        
        std::sort(workers.begin(), workers.end(), cmp);
        
        std::priority_queue<long long> pq;
        long long res = 0;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += workers[i].speed;
            pq.push(-workers[i].speed);
            
            if (pq.size() > k) {
                sum += pq.top();
                pq.pop();
            }
            
            res = std::max(res, sum * workers[i].eff);
        }
        
        return res % mod;
    }
};
