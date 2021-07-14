std::unordered_map<char, int> mp;

class Solution {
public:
    string customSortString(string order, string str) {
        mp.clear();
        for (int i = 0; i < order.size(); i++) {
            mp[order[i]] = i;
        }
        
        std::sort(str.begin(), str.end(), [](const char a, const char b) {
            return mp[a] < mp[b];
        });
        
        return str;
    }
};