class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int maxSize = 0;
        int size = 0;
        int aLast = -1;
        int bLast = -1;
        char a, b;
        for (int i = 0; i < s.size(); i++) {
            if (aLast == -1) {
                aLast = i;
                a = s[i];
                size++;
            } else if (s[i] == a) {
                aLast = i;
                size++;
            } else if (bLast == -1) {
                bLast = i;
                b = s[i];
                size++;
            } else if (s[i] == b) {
                bLast = i;
                size++;
            } else {
                if (aLast > bLast) {
                    b = s[i];
                    size = i - bLast;
                    bLast = i;
                } else {
                    a = s[i];
                    size = i - aLast;
                    aLast = i;
                }
            }
            
            maxSize = std::max(maxSize, size);
        }
        
        return maxSize;
    }
};