class Solution {
public:
    string frequencySort(string s) {
        std::unordered_map<char, int> mp;
        for (const char c : s) {
            mp[c]++;
        }
        
        std::vector<std::pair<int, char>> v;
        for (const auto & [k, vv] : mp) {
            v.push_back({vv, k});
        }
        
        std::sort(v.begin(), v.end(), std::greater<>());
        
        std::string res;
        for (int i = 0; i < v.size(); i++) {
            res += std::string(v[i].first, v[i].second);
        }
        
        return res;
    }
};