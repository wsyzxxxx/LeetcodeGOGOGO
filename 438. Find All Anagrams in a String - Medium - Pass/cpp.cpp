class Solution {
private:
    int bucket[26] = {0};
    
    bool allZero() {
        for (int i = 0; i < 26; i++) {
            if (bucket[i] != 0) {
                return false;
            }
        }
        
        return true;
    }
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.length() < p.length()) {
            return {};
        }
        
        //std::memset(bucket, 0, sizeof(bucket));
        for (int i = 0; i < p.length(); i++) {
            bucket[p[i]-'a']++;
        }
        for (int i = 0; i < p.length(); i++) {
            bucket[s[i]-'a']--;
        }
        
        std::vector<int> result;
        if (allZero()) {
            result.push_back(0);
        }
        
        for (int i = p.length(); i < s.length(); i++) {
            bucket[s[i]-'a']--;
            bucket[s[i - p.length()]-'a']++;
            
            if (allZero()) {
                result.push_back(i - p.length() + 1);
            }
        }
        
        return result;
    }
};