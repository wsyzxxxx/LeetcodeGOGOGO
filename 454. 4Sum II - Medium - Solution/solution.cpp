class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        std::unordered_map<int, int> mp;
        int res = 0;
        for (const auto a : A) {
            for (const auto b : B) {
                mp[a+b]++;
            }
        }
        
        for (const auto c : C) {
            for (const auto d : D) {
                auto it = mp.find(0 - c - d);
                if (it != mp.end()) {
                    res += it->second;
                }
            }
        }
        
        return res;
    }
};
