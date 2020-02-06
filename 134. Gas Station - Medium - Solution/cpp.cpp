class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (gas.empty() || cost.empty() || gas.size() != cost.size()) {
            return -1;
        }
        
        int restGas = -1;
        int startPos = 0;
        int totalGas = 0;
        for (int i = 0; i < gas.size(); i++) {
            if (restGas < 0) {
                restGas = gas[i] - cost[i];
                startPos = i;
            } else {
                restGas += gas[i] - cost[i];
            }
            totalGas += gas[i] - cost[i];
        }
        
        if (totalGas >= 0) {
            return startPos;
        } else {
            return -1;
        }
    }
};
