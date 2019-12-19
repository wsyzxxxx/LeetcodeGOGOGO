class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        std::vector<int> res;
        if (input.empty() || k > input.size() || k < 1) {
            return res;
        }
        
        std::make_heap(res.begin(), res.end());
        for (int i = 0; i < input.size(); i++) {
            if (res.size() < k) {
                res.push_back(input[i]);
                std::push_heap(res.begin(), res.end());
            } else {
                if (input[i] < res.front()) {
                    std::pop_heap(res.begin(), res.end());
                    res.pop_back();
                    res.push_back(input[i]);
                    std::push_heap(res.begin(), res.end());
                }
            }
        }
        
        return res;
    }
};
