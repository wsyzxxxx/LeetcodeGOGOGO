class Solution {
public:
    int longestDecomposition(string text) {
        if (text.empty()) {
            return 0;
        }
        
        int res = 1;
        int start = 0;
        int end = text.size()-1;
        int last = end;
        while (start < end) {
            while (start < end && text[start] != text[end]) {
                end--;
            }
            int len = last - end + 1;
            if (start < end && text.substr(start, len) == text.substr(end, len)) {
                res += 2;
                start = start + len;
                last = end - 1;
                if (last == start - 1) {
                    res--;
                }
            }
            end--;
        }
        
        return res;
    }
};
