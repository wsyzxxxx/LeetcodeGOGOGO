int bucket[26];

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (n == 0) {
            return tasks.size();
        }
        
        std::memset(bucket, 0, sizeof(bucket));
        
        for (char c : tasks) {
            bucket[c-'A']++;
        }
        
        std::sort(bucket, bucket+26, std::greater<int>());
        
        int res = (bucket[0] - 1) * n + bucket[0];
        //std::cout << bucket[0] << std::endl;
        
        for (int i = 1; i < 26; i++) {
            //std::cout << bucket[i] << std::endl;
            if (bucket[i] == bucket[0]) {
                res++;
            }
        }
        
        return std::max(res, (int)tasks.size());
    }
};