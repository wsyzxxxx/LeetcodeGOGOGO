class Solution {
private:
    int mod = 1e9 + 7;
public:
    int uniqueLetterString(string S) {
        int n = S.length();
        
        if (n == 0) {
            return 0;
        }
        
        long long sum = 0;
        int record[26][2];
        std::memset(record, -1, sizeof(record));
        for (int i = 0; i < n; i++) {
            int ch = S[i] - 'A';
            sum = (sum + (record[ch][1] - record[ch][0]) * (i - record[ch][1])) % mod;
            record[ch][0] = record[ch][1];
            record[ch][1] = i;
        }
        
        for (int i = 0; i < 26; i++) {
            sum = (sum + (n - record[i][1]) * (record[i][1] - record[i][0])) % mod;
        }
        
        return sum % mod;
    }
};
