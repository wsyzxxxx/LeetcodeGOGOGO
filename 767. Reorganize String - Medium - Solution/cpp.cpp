bool cmp(const std::pair<int, int> & a, const std::pair<int, int> & b) {
    return a.second > b.second;
}

class Solution {
public:
    string reorganizeString(string s) {
        std::vector<std::pair<int, int>> bucket;
        for (int i = 0; i < 26; i++) {
            bucket.push_back({i, 0});
        }
        for (const char c : s) {
            bucket[c-'a'].second++;
        }
        
        std::sort(bucket.begin(), bucket.end(), cmp);
        
        if (bucket[0].second > (int)s.size()/2+(s.size() % 2 == 0 ? 0 : 1)) {
            return "";
        }
        
        std::string result = s;
        int p = 0;
        for (int i = 0; i < 26; i++) {
            if (bucket[i].second > 0) {
                if (p >= s.size()) {
                    p = 1;
                }
                result[p] = bucket[i].first + 'a';
                bucket[i].second--;
                p += 2;
                i--;
            }
        }
        
        return result;
    }
};