struct Job {
    int start;
    int end;
    int profit;
    int DoProfit = 0;
    int NotDoProfit = 0;
    Job(int _start, int _end, int _profit) : start(_start), end(_end), profit(_profit) {}
};
std::vector<Job> jobs;

bool cmp(const Job & a, const Job & b) {
    return a.end < b.end;
}

//int dp[50002][2];

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        if (startTime.empty() || endTime.empty() || profit.empty()) {
            return 0;
        }
        jobs.clear();
        for (int i = 0; i < startTime.size(); i++) {
            Job jobItem(startTime[i], endTime[i], profit[i]);
            jobs.push_back(jobItem);
        }
        
        std::sort(jobs.begin(), jobs.end(), cmp);
        
        int n = startTime.size();
        jobs[0].DoProfit = jobs[0].profit;
        jobs[0].NotDoProfit = 0;
        for (int i = 1; i < startTime.size(); i++) {
            jobs[i].NotDoProfit = std::max(jobs[i-1].NotDoProfit, jobs[i-1].DoProfit);
            int j;
            for (j = i-1; j >= 0 && jobs[j].end > jobs[i].start; j--);
            if (j >= 0) {
                jobs[i].DoProfit = std::max(jobs[j].NotDoProfit, jobs[j].DoProfit) + jobs[i].profit;
            } else {
                jobs[i].DoProfit = jobs[i].profit;
            }
            //std::cout << i << " " << jobs[i].DoProfit << std::endl;
        }
        
        return std::max(jobs[n-1].DoProfit, jobs[n-1].NotDoProfit);
    }
};
