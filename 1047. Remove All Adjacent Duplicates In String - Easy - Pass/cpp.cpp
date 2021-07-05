class Solution {
public:
    string removeDuplicates(string s) {
        std::string result;
        for (const char ch : s) {
            if (!result.empty() && result.back() == ch) {
                result.pop_back();
            } else {
                result += ch;
            }
        }
        
        return result;
    }
};