class Solution {
private:
    int findMaxDec(std::string & text, int start, int end) {
        if (start > end) {
            return 0;
        }
        if (start == end) {
            return 1;
        }
        
        int res = 1;
        int mid = (start + end) / 2;
        for (int i = end; i > mid; i--) {
            if (text[i] == text[start]) {
                int left = start;
                int right = i;
                while (text[left] == text[right] && right <= end) {
                    right++;
                    left++;
                }
                if (right > end) {
                    res = 2;
                    res += findMaxDec(text, left, i - 1);
                    break;
                }
            }
        }
        
        return res;
    }
public:
    int longestDecomposition(string text) {
        if (text.empty()) {
            return 0;
        }
        
        return findMaxDec(text, 0, text.size()-1);
    }
};
