class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int maxSize = 0;
        int currSize = 0;
        std::queue<int> q;
        for (int i = 0; i < A.size(); i++) {
            if (A[i] == 0) {
                if (q.size() < K) {
                    q.push(i);
                    currSize++;
                } else if (!q.empty()) {
                    currSize = i - q.front();
                    q.pop();
                    q.push(i);
                } else {
                    currSize = 0;
                }
            } else {
                currSize++;
            }
            
            maxSize = std::max(maxSize, currSize);
        }
        
        return maxSize;
    }
};