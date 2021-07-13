class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        
        std::unordered_map<char, char> mp1, mp2;
        for (int i = 0; i < s.size(); i++) {
            if (mp1.find(s[i]) == mp1.end()) {
                mp1[s[i]] = t[i];
            }
            if (mp2.find(t[i]) == mp2.end()) {
                mp2[t[i]] = s[i];
            }
            if (mp1[s[i]] != t[i] || mp2[t[i]] != s[i]) {
                return false;
            }
        }
        
        return true;
    }
};