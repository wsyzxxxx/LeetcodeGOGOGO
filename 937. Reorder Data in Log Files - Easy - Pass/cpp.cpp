inline bool cmp(const std::string & a, const std::string & b) {
    int i = 0, j = 0;
    while (i < a.size() && a[i++] != ' ');
    while (j < b.size() && b[j++] != ' ');
    
    while (i < a.size() && j < b.size()) {
        if (a[i] != b[j]) {
            return a[i] < b[j];
        }
        i++;
        j++;
    }
    for (int i = 0; i < a.size() && i < b.size(); i++) {
        if (a[i] != b[i]) {
            return a[i] < b[i];
        }
    }
    return a.size() < b.size();
}

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        int n = logs.size();
        
        int digitIndex = n;
        for (int i = n-1; i >= 0; i--) {
            int j = 0;
            while (j < logs[i].size() && logs[i][j++] != ' ');
            
            if (logs[i][j] >= '0' && logs[i][j] <= '9') {
                digitIndex--;
                if (digitIndex != i) {
                    std::swap(logs[i], logs[digitIndex]);
                }
            }
        }
        
        if (digitIndex == 0) {
            return logs;
        }
        
        for (int i = 0; i < digitIndex; i++) {
            int minIndex = i;
            for (int j = i+1; j < digitIndex; j++) {
                if (cmp(logs[j], logs[minIndex])) {
                    minIndex = j;
                }
            }
            if (minIndex != i) {
                std::swap(logs[i], logs[minIndex]);
            }
        }
        
        return logs;
    }
};
