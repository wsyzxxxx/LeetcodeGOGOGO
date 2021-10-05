class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        std::string res;
        for (const auto & str : strs) {
            std::string len = std::to_string(str.size());
            res += std::string(4 - len.size(), '0') + len + str;
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        std::vector<std::string> res;
        for (int i = 0; i < s.size(); ) {
            int len = std::stoi(s.substr(i, 4));
            res.push_back(s.substr(i+4, len));
            i += 4 + len;
        }
        
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));