class Solution {
private:
    std::string decodeString(std::string & s, int & currPos) {
        if (currPos >= s.size()) {
            return "";
        }
        std::string res = "";
        
        while (currPos < s.size() && s[currPos] != ']') {
            if (s[currPos] >= '0' && s[currPos] <= '9') {
                int count = 0;
                while (currPos < s.size() && s[currPos] >= '0' && s[currPos] <= '9') {
                    count = count * 10 + s[currPos] - '0';
                    currPos++;
                }
                currPos++;
                std::string next = decodeString(s, currPos);
                while (count--) {
                    res += next;
                }
                currPos++;
            } else {
                res += s[currPos++];
            }
        }
        
        return res;
    }
public:
    string decodeString(string s) {
        if (s.empty()) {
            return "";
        }
        
        int currPos = 0;
        return decodeString(s, currPos);
    }
};
