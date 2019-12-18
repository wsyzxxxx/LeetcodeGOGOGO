#include <cstdlib>
#include <iostream>

class Solution {
public:
    bool isNumeric(char* string) {
        if (string == NULL || *string == '\0') {
            return false;
        }
        
        bool hasInteger = false;
        bool hasPoint = false;
        size_t i = 0;
        if (string[i] == '+' || string[i] == '-') {
            i++;
            while (string[i] >= '0' && string[i] <= '9') {
                i++;
                hasInteger = true;
            }
        } else if (string[i] >= '0' && string[i] <= '9') {
            hasInteger = true;
            while (string[i] >= '0' && string[i] <= '9') {
                i++;
            }
        }
        
        if (string[i] == '.') {
            i++;
            while (string[i] >= '0' && string[i] <= '9') {
                i++;
                hasPoint = true;
            }
        }
        
        if (hasInteger || hasPoint) {
            if (string[i] == 'e' || string[i] == 'E') {
                i++;
                hasInteger = false;
                if (string[i] == '+' || string[i] == '-') {
                    i++;
                    while (string[i] >= '0' && string[i] <= '9') {
                        i++;
                        hasInteger = true;
                    }
                } else if (string[i] >= '0' && string[i] <= '9') {
                    hasInteger = true;
                    while (string[i] >= '0' && string[i] <= '9') {
                        i++;
                    }
                }
            } else if (string[i] == '\0') {
                return true;
            }
        } else {
            return false;
        }
        
        if (hasInteger && string[i] == '\0') {
            return true;
        } else {
            return false;
        }
    }

};
int main(void) {
	Solution s;
	s.isNumeric("5e2");
}
