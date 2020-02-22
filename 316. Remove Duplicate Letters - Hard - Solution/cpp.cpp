class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        
        if (n == 0) {
            return s;
        }
        
        int bucket[26];
        bool visited[26];
        std::memset(visited, 0, sizeof(visited));
        std::memset(bucket, 0, sizeof(bucket));
        for (const auto ch : s) {
            bucket[ch - 'a']++;
        }
        
        std::string res;
        for (const auto ch : s) {
            if (!visited[ch - 'a']) {
                while (!res.empty() && res.back() >= ch) {
                    if (bucket[res.back() - 'a'] > 0) {
                        visited[res.back() - 'a'] = false;
                        res.pop_back();
                    } else {
                        break;
                    }
                }
                visited[ch - 'a'] = true;
                res.push_back(ch);
            }
            bucket[ch - 'a']--;
        }
        
        return res;
    }
};
