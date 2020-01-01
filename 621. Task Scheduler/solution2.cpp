class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (tasks.empty() || n < 0) {
            return 0;
        }
        
        std::unordered_map<char, int> taskFreq;
        int maxFreq = 0;
        int maxCount = 1;
        for (auto i : tasks) {
            taskFreq[i]++;
            if (maxFreq == taskFreq[i]) {
                maxCount++;
            } else if (maxFreq < taskFreq[i]) {
                maxCount = 1;
                maxFreq = taskFreq[i];
            }
        }
        
        int partCount = maxFreq - 1;
        int partLen = n - (maxCount - 1);
        int reqTasks = partCount * partLen;
        int availableTasks = tasks.size() - maxCount * maxFreq;
        int idles = std::max(0, reqTasks - availableTasks);
        
        return tasks.size() + idles;
    }
};
