class Solution {
private:
    bool regularMatch(char* str, char* pattern) {
        if (*str == '\0' && *pattern == '\0') {
            return true;
        }
        if (*str != '\0' && *pattern == '\0') {
            return false;
        }
        
        if (*(pattern + 1) == '*') {
            if (((*pattern == '.') && *str != '\0') || (*str == *pattern)) {
            return    regularMatch(str+1, pattern) || 
                      regularMatch(str+1, pattern+2) ||
                      regularMatch(str, pattern+2);
            } else {
                return regularMatch(str, pattern+2);
            }
        }
        
        if (*pattern == '.' && *str != '\0') {
            return regularMatch(str+1, pattern+1);
        } else {
            return (*str == *pattern) && regularMatch(str+1, pattern+1);
        }
    }
public:
    bool match(char* str, char* pattern) {
        if (str == NULL || pattern == NULL) {
            return NULL;
        }
        
        return regularMatch(str, pattern);
    }
};
