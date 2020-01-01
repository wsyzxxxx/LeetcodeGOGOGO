class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (tasks.empty() || n < 0) {
            return 0;
        }
        
        std::unordered_map<char, int> taskFreq;
        int maxFreq = 0;
        for (auto i : tasks) {
            taskFreq[i]++;
            maxFreq = std::max(maxFreq, taskFreq[i]);
        }
        
        int res = (maxFreq - 1) * (n + 1);
        for (auto i : taskFreq) {
            if (i.second == maxFreq) {
                res++;
            }
        }
        
        return std::max(res, (int)tasks.size());
    }
};
