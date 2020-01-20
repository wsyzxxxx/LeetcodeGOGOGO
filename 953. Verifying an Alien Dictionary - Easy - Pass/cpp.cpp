class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        for (int i = 1; i < words.size(); i++) {
            int pos = 0;
            while (pos < words[i-1].size() && 
                   pos < words[i].size() && 
                   words[i-1][pos] == words[i][pos]) {
                pos++;
            }
            if (pos == words[i-1].size()) {
                continue;
            } else if (pos == words[i].size()) {
                return false;
            } else {
                int in1 = 0;
                int in2 = 0;
                for (int j = 0; j < order.size(); j++) {
                    if (order[j] == words[i-1][pos]) {
                        in1 = j;
                    }
                    if (order[j] == words[i][pos]) {
                        in2 = j;
                    }
                }
                if (in2 < in1) {
                    return false;
                }
            }
        }
        
        return true;
    }
};
