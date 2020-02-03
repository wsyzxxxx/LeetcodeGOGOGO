class Solution {
public:
    string addBinary(string a, string b) {
        if (a.empty()) {
            return b;
        }
        if (b.empty()) {
            return a;
        }
        
        int indexa = a.size() - 1;
        int indexb = b.size() - 1;
        
        int curr = 0;
        std::string res = "";
        while (indexa >= 0 || indexb >= 0 || curr) {
            if (indexa >= 0) {
                curr += (a[indexa] == '1') ? 1 : 0;
                indexa--;
            }
            
            if (indexb >= 0) {
                curr += (b[indexb] == '1') ? 1 : 0;
                indexb--;
            }
            
            res = ((curr & 1) ? "1" : "0") + res;
            curr = curr >> 1;
        }
        
        return res;
    }
};
