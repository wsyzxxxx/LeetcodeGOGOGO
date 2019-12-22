class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if (data.size() < 2) {
            return;
        }
        
        int num = 0;
        for (int i = 0; i < data.size(); i++) {
            num ^= data[i];
        }
        
        int bit = 1;
        while ((num & bit) == 0) {
            bit <<= 1;
        }
        
        *num1 = 0;
        *num2 = 0;
        for (int i = 0; i < data.size(); i++) {
            if (data[i] & bit) {
                *num1 ^= data[i];
            } else {
                *num2 ^= data[i];
            }
        }
    }
};
