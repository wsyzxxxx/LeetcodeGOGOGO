class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string max_len_string;
        string temp_string;
        max_len_string = s.substr(0, 1);
        temp_string = s.substr(0, 1);
        
        //int last_index = 0;
        
        for (int i = 1; i < s.length(); i++) {
            if (temp_string.find(s.substr(i, 1)) == std::string::npos) {
                temp_string += s.substr(i, 1);
            } else {
                if (temp_string.length() > max_len_string.length()) {
                    max_len_string = temp_string;
                }
                
                size_t index = temp_string.find(s.substr(i, 1));
                temp_string = temp_string.substr(index + 1, temp_string.length() - index - 1) + s.substr(i, 1);
            }
        }
        
        if (temp_string.length() > max_len_string.length()) {
            max_len_string = temp_string;
        }
        return max_len_string.length();
    }
};
