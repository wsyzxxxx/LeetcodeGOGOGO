class Solution {
private:
    double calPower(double base, int exponent) {
        double res = base;
        int index = 2;
        while (index*2 <= exponent) {
            res *= res;
            index *= 2;
        }
        for (; index <= exponent; index++) {
            res *= base;
        }
        return res;
    }
public:
    double Power(double base, int exponent) {
        if (exponent == 0) {
            return 1.0;
        } else if (exponent == 1) {
            return base;
        }
        
        int absExponent = abs(exponent);
        double res = calPower(base, absExponent);
        
        if (exponent < 0) {
            return 1.0/res;
        } else {
            return res;
        }
    }
};
