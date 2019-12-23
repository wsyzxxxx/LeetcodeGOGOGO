class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
        std::vector<int> res;
        if (num.empty() || size <= 0) {
            return res;
        }
        
        if (size > num.size()) {
            //res.push_back(*(std::max(num.begin(), num.end())));
            return res;
        }
        
        std::deque<int> dq;
        for (unsigned int i = 0; i < size; i++) {
            while (!dq.empty() && num[i] >= num[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        
        for (unsigned int i = size; i < num.size(); i++) {
            res.push_back(num[dq.front()]);
            
            while (!dq.empty() && num[i] >= num[dq.back()]) {
                dq.pop_back();
            }
            if (!dq.empty() && dq.front() <= (i - size)) {
                dq.pop_front();
            }
            
            dq.push_back(i);
        }
        res.push_back(num[dq.front()]);
        
        return res;
    }
};
