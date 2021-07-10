class Solution {
public:
    int minSetSize(vector<int>& arr) {
        std::unordered_map<int, int> mp;
        for (const int num : arr) {
            mp[num]++;
        }
        
        std::priority_queue<std::pair<int, int>> pq;
        for (const auto & kv : mp) {
            pq.push({kv.second, kv.first});
        }
        
        int res = 0;
        int count = 0;
        while (!pq.empty() && count < arr.size() / 2) {
            count += pq.top().first;
            res++;
            pq.pop();
        }
        return res;
    }
};