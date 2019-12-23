class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if (n == 0 || m == 0) {
            return -1;
        }
        
        bool a[n];
        for (int i = 0; i < n; i++) {
            a[i] = true;
        }
        
        int count = 0;
        int i = 0;
        while (count < n - 1) {
            int temp = m-1;
            while (temp) {
                if (i == n) {
                    i = 0;
                }
                if (a[i] == true) {
                    i++;
                    temp--;
                } else {
                    i++;
                }
            }
            if (i == n) {
                i = 0;
            }
            while (a[i] == false) {
                i++;
                if (i == n) {
                    i = 0;
                }
            }
            a[i++] = false;
            if (i == n) {
                i = 0;
            }
            while (a[i] == false) {
                i++;
                if (i == n) {
                    i = 0;
                }
            }
            count++;
        }
        if (i == n) {
            i = 0;
        }
        while (a[i] == false) {
            i++;
            if (i == n) {
                i = 0;
            }
        }
        
        return i;
    }
};
