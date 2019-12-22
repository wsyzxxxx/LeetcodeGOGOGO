class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n) {
        if (n <= 0) {
            return 0;
        }
        
        if (n >= 1 && n < 10) {
            return 1;
        }
        
        int highestBit;
        int bitsNum = 0;
        int bitsValue = 1;
        int tempN = n;
        while (tempN) {
            bitsNum++;
            bitsValue *= 10;
            highestBit = tempN % 10;
            tempN /= 10;
        }
        bitsValue /= 10;
        
        int currOnes;
        if (highestBit > 1) {
            currOnes = bitsValue;
        } else {
            currOnes = n - bitsValue + 1;
        }
        
        int restOnes = highestBit * (bitsNum - 1) * (bitsValue / 10);
        
        int nextOnes = NumberOf1Between1AndN_Solution(n - bitsValue*highestBit);
        
        return currOnes + restOnes + nextOnes;
        
    }
};
