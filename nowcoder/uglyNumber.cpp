class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if (index <= 0) {
            return 0;
        }
        
        int uNum[index];
        uNum[0] = 1;
        
        int curr2 = 0;
        int curr3 = 0;
        int curr5 = 0;
        for (int i = 1; i < index; i++) {
            while (uNum[curr2]*2 <= uNum[i-1]) {
                curr2++;
            }
            while (uNum[curr3]*3 <= uNum[i-1]) {
                curr3++;
            }
            while (uNum[curr5]*5 <= uNum[i-1]) {
                curr5++;
            }
            int minOf2And3 = std::min(uNum[curr2]*2, uNum[curr3]*3);          
            int currNum = std::min(minOf2And3, uNum[curr5]*5);
            
            uNum[i] = currNum;
        }
        
        return uNum[index-1];
    }
};
