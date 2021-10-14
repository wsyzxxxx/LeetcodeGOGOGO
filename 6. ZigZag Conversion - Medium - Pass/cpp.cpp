class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows >= s.length()) {
            return s;
        }
        
        std::vector<std::string> result(numRows, "");
        for (int i = 0; i < s.length();) {
            for (int j = 0; j < numRows && i < s.length(); j++, i++) {
                result[j].push_back(s[i]);
            }
            for (int j = numRows-2; j > 0 && i < s.length(); j--, i++) {
                result[j].push_back(s[i]);
            }
        }
        
        std::string res;
        for (int i = 0; i < result.size(); i++) {
            res += result[i];
        }
        
        return res;
    }
};