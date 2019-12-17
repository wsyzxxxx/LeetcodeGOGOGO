class Solution {
private:
    int count;
    void checkPalindrom(std::string & s, int lo, int hi) {
        while (lo >= 0 && hi < s.size() && s[lo] == s[hi]) {
            count++;
            lo--;
            hi++;
        }
    }
public:
    int countSubstrings(string s) {
        count = 0;
        for (int i = 0; i < s.size(); i++) {
            checkPalindrom(s, i, i);
            checkPalindrom(s, i, i+1);
        }
        
        return count;
    }
};
