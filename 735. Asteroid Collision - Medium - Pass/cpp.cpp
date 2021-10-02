class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        std::deque<int> dq;
        std::vector<int> result;
        for (const int aster : asteroids) {
            if (aster < 0) {
                while (!dq.empty() && dq.back() < -aster) {
                    dq.pop_back();
                }
                
                if (dq.empty()) {
                    result.push_back(aster);
                } else if (dq.back() == -aster) {
                    dq.pop_back();
                }
            } else {
                dq.push_back(aster);
            }
        }
        
        while (!dq.empty()) {
            result.push_back(dq.front());
            dq.pop_front();
        }
        
        return result;
    }
};