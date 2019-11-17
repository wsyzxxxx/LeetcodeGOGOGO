class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> res(T.size());
        for (int i = T.size()-2; i >= 0; i--) {
            if (T[i] < T[i+1]) {
                res[i] = 1;
            } else {
                res[i] = 0;
                int offset = res[i+1];
                while (res[i+1+offset] != 0) {
                    if (T[i+1+offset] > T[i]) {
                        break;
                    }
                    offset += res[i+1+offset];
                }
                if (T[i+1+offset] > T[i]) {
                    res[i] = 1 + offset;
                }
            }
        }
        return res;
    }
};
