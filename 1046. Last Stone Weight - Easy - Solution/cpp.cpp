int bucket[1005];

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::memset(bucket, 0, sizeof(bucket));
        
        int mx = stones[0];
        for (int i = 0; i < stones.size(); i++) {
            bucket[stones[i]]++;
            mx = std::max(mx, stones[i]);
        }
        
        int first = 0;
        for (int i = mx; i > 0; i--) {
            if (bucket[i] > 0) {
                if (first == 0) {
                    bucket[i] &= 1;
                    if (bucket[i] > 0) {
                        first = i;
                    }
                } else {
                    bucket[i]--;
                    if (first - i > i) {
                        first = first - i;
                    } else {
                        bucket[first - i]++;
                        first = 0;
                    }
                    i++;
                }
            }
        }
        
        return first;
    }
};