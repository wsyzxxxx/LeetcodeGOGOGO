class Compare {
public:
    bool operator()(std::pair<int, int> & lhs, std::pair<int, int> & rhs) {
        return lhs.second > rhs.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::vector<int> res;
        if (k <= 0) {
            return res;
        }
        
        std::unordered_map<int, int> freqMap;
        for (size_t i = 0; i < nums.size(); i++) {
            freqMap[nums[i]]++;
        }
        
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int> >,  Compare> pq;
        std::unordered_map<int, int>::iterator it = freqMap.begin();
        while (it != freqMap.end()) {
            pq.push(*it);
            if (pq.size() > k) {
                pq.pop();
            }
            it++;
        }
        
        for (int i = 0; i < k; i++) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        
        return res;
    }
};
