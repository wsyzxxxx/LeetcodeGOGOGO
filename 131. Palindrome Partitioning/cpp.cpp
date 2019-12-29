class Solution {
private:
    bool checkPalindrome(std::string & str, int start, int end) {
        while (start < end) {
            if (str[start++] != str[end--]) {
                return false;
            }
        }
        return true;
    }
    
    void checkAllSubsets(std::string s, int currIndex,
                         std::vector<std::vector<std::string> > & res,
                         std::vector<std::string> & currSet) {
        if (currIndex == s.size()) {
            res.push_back(currSet);
        }
        
        for (int i = currIndex+1; i <= s.size(); i++) {
            if (checkPalindrome(s, currIndex, i-1)) {
                currSet.push_back(s.substr(currIndex, i - currIndex));
                checkAllSubsets(s, i, res, currSet);
                currSet.pop_back();
            }
            
        }
    }
public:
    vector<vector<string>> partition(string s) {
        std::vector<std::vector<std::string> > res;
        if (s.empty()) {
            return res;
        }
        
        std::vector<std::string> currSet;
        checkAllSubsets(s, 0, res, currSet);
        return res;
    }
};
