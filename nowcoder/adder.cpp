#include <iostream>
class Solution {
public:
    int Add(int num1, int num2) {
        int sum = 0;
        int carry = 0;
        int currBit = 1;
        while (currBit) {
	//std::cout << "bit: " << currBit << "  carry:" << carry << " num1: " << (num1 & currBit) << " num2: " << (num2 & currBit) << std::endl;
            sum |= currBit & ((currBit & num1) ^ (currBit & num2) ^ carry);
            carry = ((currBit & num1) && (currBit & num2)) ||
                    ((currBit & num1) && carry) ||
                    ((currBit & num2) && carry);
            currBit = currBit << 1;
	    carry = carry ? currBit : 0;
        }
        return sum;
    }
};

int main(void) {
	Solution so;
	std::cout << so.Add(111, 899) << std::endl;
}
