class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if (str.size() == 0) {
            return -1;
        }
        
        int characters[257];
        for (int i = 0; i < 257; i++) {
            characters[i] = -1;
        }
        for (int i = 0; i < str.size(); ++i) {
            if (characters[str[i]] == -1) {
                characters[str[i]] = i;
            } else if (characters[str[i]] >= 0) {
                characters[str[i]] = -2;
            }
        }
        
        int minNum = INT_MAX;
        bool exist = false;
        for (int i = 0; i < 256; i++) {
            if (characters[i] > 0) {
                exist = true;
            }
            if (characters[i] >= 0 && characters[i] < minNum) {
                minNum = characters[i];
            }
        }
        
        if (exist) {
            return minNum;
        } else {
            return -1;
        }
    }
};
