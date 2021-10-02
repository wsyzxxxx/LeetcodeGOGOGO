class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        std::unordered_map<int, std::set<int>> xToys;
        
        for (const auto & point : points) {
            xToys[point[0]].insert(point[1]);
        }
        
        int minSize = INT_MAX;
        auto it1 = xToys.begin();
        auto it2 = it1;
        while(it1 != xToys.end()) {
            it2 = it1;
            it2++;
            while (it2 != xToys.end()) {
                int xdist = std::abs(it2->first - it1->first);
                
                auto iit1 = it1->second.begin();
                auto iit2 = it2->second.begin();
                
                int last = -1;
                while (iit1 != it1->second.end() && iit2 != it2->second.end()) {
                    if (*iit1 == *iit2) {
                        if (last == -1) {
                            last = *iit1;
                        } else {
                            minSize = std::min(minSize, xdist * std::abs(*iit1 - last));
                            last = *iit1;
                        }
                        iit1++;
                        iit2++;
                    } else if (*iit1 < *iit2) {
                        iit1++;
                    } else {
                        iit2++;
                    }
                }
                
                it2++;
            }
            it1++;
        }
        
        return minSize == INT_MAX ? 0 : minSize;
    }
};