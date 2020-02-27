// class Compare {
// public:
//     bool operator()(const std::pair<char, int> & a, const std::pair<char, int> & b) {
//         return a.second > b.second;
//     }
// };
class Solution {
public:
    string alienOrder(vector<string>& words) {
        if (words.empty()) {
            return "";
        }
        
        std::unordered_map<char, int> inNum;
        std::unordered_map<char, std::vector<char> > edges;
        for (int i = 0; i < words.size(); i++) {
            const std::string & prev = i > 0 ? words[i-1] : "";
            const std::string & next = words[i];
            bool first = true;
            for (int j = 0; j < std::max(prev.size(), next.size()); j++) {
                if (j < prev.size() && inNum[prev[j]] == 0) {
                    inNum[prev[j]] = 1;
                }
                if (j < next.size() && inNum[next[j]] == 0) {
                    inNum[next[j]] = 1;
                }
                if (j < prev.size() && j < next.size() && prev[j] != next[j] && first) {
                    inNum[next[j]]++;
                    edges[prev[j]].push_back(next[j]);
                    first = false;
                }
            }
        }
        
        std::string res;
        std::queue<char> q;
        for (const auto point : inNum) {
            if (point.second == 1) {
                q.push(point.first);
            }
        }
        
        while (!q.empty()) {
            const auto point = q.front();
            q.pop();
            res.push_back(point);
            
            for (const auto i : edges[point]) {
                inNum[i]--;
                if (inNum[i] == 1) {
                    q.push(i);
                }
            }
        }
        
        if (res.size() == edges.size()) {
            return res;
        } else {
            return "";
        }
    }
};
