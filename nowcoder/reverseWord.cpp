class Solution {
private:
    void reverseWord(std::string & str, int start, int end) {
        end = end - 1;
        while (start < end) {
            std::swap(str[start], str[end]);
            start++;
            end--;
        }
    }
public:
    string ReverseSentence(string str) {
        if (str == "") {
            return "";
        }
        
        reverseWord(str, 0, str.size());
        
        for (int start = 0; start < str.size();) {
            int end = start;
            while (end < str.size() && str[end] != ' ') {
                end++;
            }
            reverseWord(str, start, end);
            start = end + 1;
        }
        
        return str;
    }
};
