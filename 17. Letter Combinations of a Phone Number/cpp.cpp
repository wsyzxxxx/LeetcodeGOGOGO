class Solution {
private:
    void findAllComb(std::vector<std::string> & res, std::string & digits, int currIndex, std::string currStr) {
        if (currIndex == digits.size()) {
            res.push_back(currStr);
            return;
        }

        int end = (digits[currIndex] == '9' || digits[currIndex] == '7') ? 4 : 3;
        int carry = digits[currIndex] > '7' ? 1 : 0;

        for (int i = 0; i < end; i++) {
            std::string temp = currStr + (char)((digits[currIndex] - '2') * 3 + i + carry + 'a');
            findAllComb(res, digits, currIndex+1, temp);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        std::vector<std::string> res;
        if (digits.empty()) {
            return res;
        }

        findAllComb(res, digits, 0, "");
        return res;
    }
};