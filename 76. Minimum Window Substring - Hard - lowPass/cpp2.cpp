class Solution {
public:
    string minWindow(string s, string t) {
        std::unordered_map<char, int> mp;
        int count = 0;
        for (int i = 0; i < t.size(); i++) {
            mp[t[i]]++;
            count++;
        }
        
        std::string result = "";
        int start = 0;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]--;
            if (mp[s[i]] >= 0) {
                count--;
            }
            
            if (count == 0) {
                while (count == 0 && start <= i) {
                    mp[s[start]]++;
                    
                    if (mp[s[start++]] > 0) {
                        count++;
                    }
                }
                
                if (result == "" || result.size() > i - start + 2) {
                    result = s.substr(start - 1, i - start + 2);
                }
            }
        }
        
        return result;
    }
};