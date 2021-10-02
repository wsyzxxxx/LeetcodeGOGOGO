class Solution {
private:
    int minTrans;
    void backTracking(int i,
                      std::vector<int>& receivers,
                      std::vector<int>& payers,
                      int currCount) {
        if (i == receivers.size()) {
            minTrans = std::min(minTrans, currCount);
        }
        
        for (int j = 0; j < payers.size(); j++) {
            if (payers[j] == 0) {
                continue;
            }
            int amount = std::min(payers[j], receivers[i]);
            payers[j] -= amount;
            receivers[i] -= amount;
            
            if (receivers[i] == 0) {
                backTracking(i+1, receivers, payers, currCount+1);
            } else {
                backTracking(i, receivers, payers, currCount+1);
            }
            
            payers[j] += amount;
            receivers[i] += amount;
        }
    }
public:
    int minTransfers(vector<vector<int>>& transactions) {
        std::vector<int> persons(22, 0);
        
        for (const auto & transac : transactions) {
            persons[transac[0]] += transac[2];
            persons[transac[1]] -= transac[2];
        }
        
        std::vector<int> receivers;
        for (int i = 0; i < 22; i++) {
            if (persons[i] > 0) {
                receivers.push_back(persons[i]);
            }
        }
        
        std::vector<int> payers;
        for (int i = 0; i < 22; i++) {
            if (persons[i] < 0) {
                payers.push_back(-persons[i]);
            }
        }
        
        minTrans = transactions.size();
        int baseCount = 0;
        for (int i = 0; i < receivers.size(); i++) {
            for (int j = 0; j < payers.size(); j++) {
                if (receivers[i] == payers[j]) {
                    std::swap(receivers[i], receivers.back());
                    std::swap(payers[j], payers.back());
                    receivers.pop_back();
                    payers.pop_back();
                    baseCount++;
                    i--;
                    break;
                }
            }
        }
        
        backTracking(0, receivers, payers, baseCount);
        
        return minTrans;
    }
};