class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        std::vector<int> zeroLeft(n), oneLeft(n), zeroRight(n), oneRight(n);
        
        zeroLeft[0] = s[0] == '0' ? 0 : 1;
        oneLeft[0] = 1 - zeroLeft[0];
        for (int i = 1; i < n; i++) {
            char ch = i % 2 == 0 ? '0' : '1';
            zeroLeft[i] = zeroLeft[i-1] + (s[i] == ch ? 0 : 1);
            oneLeft[i] = oneLeft[i-1] + (s[i] == ch ? 1 : 0);
        }
        zeroRight[n-1] = s.back() == '0' ? 0 : 1;
        oneRight[n-1] = 1 - zeroRight[n-1];
        for (int i = n-2; i >= 0; i--) {
            char ch = (n-i) % 2 == 0 ? '1' : '0';
            zeroRight[i] = zeroRight[i+1] + (s[i] == ch ? 0 : 1);
            oneRight[i] = oneRight[i+1] + (s[i] == ch ? 1 : 0);
        }
        
        int minOps = std::min(zeroLeft[n-1], std::min(zeroRight[0], std::min(oneLeft[n-1], oneRight[0])));
        //std::cout << zeroLeft[n-1] << " " << zeroRight[0] << " " << oneLeft[n-1] << " " << oneRight[0] << std::endl;
        if (n % 2 == 0) {
            return minOps;
        }
        for (int i = 0; i < n-1; i++) {
            minOps = std::min(minOps, std::min(zeroLeft[i] + oneRight[i+1], oneLeft[i] + zeroRight[i+1]));
        }
        
        return minOps;
    }
};
