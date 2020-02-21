class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> bucket;
        for (const auto letter : magazine)
            bucket[letter]++;
        
        for (const auto letter : ransomNote) {
            bucket[letter]--;
            if (bucket[letter] < 0) {
                return false;
            }
        }
        
        return true;
    }
};
