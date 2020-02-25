class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        int n = digits.size();
        
        if (n == 0) {
            return "";
        }
        
        int cnt[3];
        int bucket[10];
        std::memset(cnt, 0, sizeof(cnt));
        std::memset(bucket, 0, sizeof(bucket));
        
        int mod = 0;
        for (int i = 0; i < digits.size(); i++) {
            bucket[digits[i]]++;
            cnt[digits[i] % 3]++;
            mod = (mod + digits[i]) % 3;
        }
        
        if (mod == 1) {
            if (cnt[1] > 0) {
                for (int i = 0; i <= 9; i++) {
                    if (bucket[i] > 0 && i % 3 == 1) {
                        bucket[i]--;
                        break;
                    }
                }
            } else {
                int count = 2;
                for (int i = 0; i <= 9 && count > 0; i++) {
                    if (bucket[i] > 0 && i % 3 == 2 && count > 0) {
                        bucket[i]--;
                        count--;
                        i--;
                    }
                }
            }
        } else if (mod == 2) {
            if (cnt[2] > 0) {
                for (int i = 0; i <= 9; i++) {
                    if (bucket[i] > 0 && i % 3 == 2) {
                        bucket[i]--;
                        break;
                    }
                }
            } else {
                int count = 2;
                for (int i = 0; i <= 9 && count > 0; i++) {
                    if (bucket[i] > 0 && i % 3 == 1 && count > 0) {
                        bucket[i]--;
                        count--;
                        i--;
                    }
                }
            }
        }
        
        std::string res;
        for (int i = 9; i >= 0; i--) {
            while (bucket[i] > 0) {
                res += (char)(i + '0');
                bucket[i]--;
            }
        }
        
        if (res.empty()) {
            return "";
        }
        if (res[0] == '0') {
            return "0";
        }
        return res;
    }
};
