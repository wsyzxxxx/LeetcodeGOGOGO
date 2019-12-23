class Solution {
private:
    void reverseWord(std::string & str, int start, int end) {
        while (start < end) {
            std::swap(str[start], str[end]);
            start++;
            end--;
        }
    }
public:
    string LeftRotateString(string str, int n) {
        if (n <= 0 || n >= str.size()) {
            return str;
        }
        
        reverseWord(str, 0, n-1);
        reverseWord(str, n, str.size()-1);
        reverseWord(str, 0, str.size()-1);
        
        return str;
    }
};
