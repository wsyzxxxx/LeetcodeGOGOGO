class Solution {
private:
    int memo[1002][1002];
    int findMaxDec(std::string & text, int start, int end) {
        if (start > end) {
            return 0;
        }
        if (start == end) {
            return 1;
        }
        if (memo[start][end] != -1) {
            return memo[start][end];
        }
        
        memo[start][end] = 1;
        int mid = (start + end) / 2;
        for (int i = end; i > mid; i--) {
            if (text[i] == text[start]) {
                //std::cout << start << " " << i << std::endl;
                int left = start;
                int right = i;
                while (text[left] == text[right] && right <= end) {
                    right++;
                    left++;
                }
                if (right > end) {
                    memo[start][end] = 2;
                    memo[start][end] += findMaxDec(text, left, i - 1);
                    break;
                }
            }
        }
        
        return memo[start][end];
    }
public:
    int longestDecomposition(string text) {
        if (text.empty()) {
            return 0;
        }
        
        std::memset(memo, -1, sizeof(memo));
        
        return findMaxDec(text, 0, text.size()-1);
    }
};
