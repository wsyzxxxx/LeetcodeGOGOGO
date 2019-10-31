#include <algorithm>
#include <vector>
#include <unordered_map>


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<int> resV(2);
        std::unordered_map<int, int> storeMap;
        std::vector<int>::iterator it = nums.begin();
        std::unordered_map<int, int>::iterator mapIt;
        while (it != nums.end()) {
            mapIt = storeMap.find(target - *it);
            if (mapIt != storeMap.end()) {
                resV[0] = it - nums.begin();
                resV[1] = mapIt->second;
                return resV;
            } else {
                storeMap.insert(std::pair(*it, it - nums.begin()));
            }
            it++;
        }
        
        resV[0] = 0;
        resV[1] = 0;
        return resV;
    }
};