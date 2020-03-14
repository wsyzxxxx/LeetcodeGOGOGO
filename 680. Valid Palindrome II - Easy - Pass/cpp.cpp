class Solution {
private:
    bool validPalindrome(std::string & s, int l, int r, bool curr) {
        if (l >= r) {
            return true;
        }
        if (s[l] == s[r]) {
            return validPalindrome(s, l+1, r-1, curr);
        }
        if (!curr) {
            return false;
        }
        
        return validPalindrome(s, l+1, r, false) ||
               validPalindrome(s, l, r-1, false);
    }
public:
    bool validPalindrome(string s) {
        if (s.length() <= 1) {
            return true;
        }
        
        return validPalindrome(s, 0, s.size()-1, true);
    }
};
