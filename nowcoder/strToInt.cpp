class Solution {
public:
    int StrToInt(string str) {
        if (str == "") {
            return 0;
        }
        
        long num = 0;
        long flag = 1;
        bool hasNum = false;
        for (int i = 0; i < str.size(); i++) {
            if (i == 0) {
                if (str[i] == '-') {
                    flag = -1;
                    i++;
                } else if (str[i] == '+') {
                    i++;
                }
            }
            if (str[i] >= '0' && str[i] <= '9') {
                hasNum = true;
                num = num * 10 + str[i] - '0';
            } else {
                return 0;
            }
        }
        
        num *= flag;
        if (hasNum && num >= INT_MIN && num <= INT_MAX) {
            return num;
        } else {
            return 0;
        }
    }
};
