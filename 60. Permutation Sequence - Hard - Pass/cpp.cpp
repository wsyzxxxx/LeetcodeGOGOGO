int perms[11] = {0};

class Solution {
public:
    string getPermutation(int n, int k) {
        perms[0] = 1;
        perms[1] = 1;
        for (int i = 2; i < 11; i++) {
            perms[i] = perms[i-1] * i;
        }
        std::vector<bool> avail(n, true);
        
        std::string res;
        for (int i = 0; i < n; i++) {
            int num = 1;
            if (k > perms[n-i-1]) {
                num = (k-1) / perms[n-i-1];
                k -= num * perms[n-i-1];
                num++;
            }
            int index = 0;
            int count = 0;
            while (count < num) {
                if (avail[index]) {
                    count++;
                }
                index++;
            }
            avail[index-1] = false;
            res += index + '0';
        }
        
        return res;
    }
};