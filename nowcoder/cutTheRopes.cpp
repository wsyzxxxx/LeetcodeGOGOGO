class Solution {
public:
    int cutRope(int number) {
        if (number <= 0) {
            return 0;
        }
        if (number == 1) {
            return 0;
        }
        if (number == 2) {
            return 1;
        }
        if (number == 3) {
            return 2;
        }
        int products[number+1];
        products[0] = 0;
        products[1] = 1;
        products[2] = 2;
        products[3] = 3;
        
        int max = 0;
        for (int i = 4; i <= number; i++) {
            max = 0;
            for (int j = 1; j <= i / 2; j++) {
                int product = products[j] * products[i-j];
                if (max < product) {
                    max = product;
                }
            }
            products[i] = max;
        }
        
        return products[number];
    }
};
