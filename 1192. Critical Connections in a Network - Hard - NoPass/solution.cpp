class Solution {
private:
    void dfs(std::vector<std::vector<int> > & graph, std::vector<int> & low, int last,
             std::vector<std::vector<int> > & res, int curr, int currV) {
        low[curr] = currV++;
        
        for (const auto edge : graph[curr]) {
            if (edge == last) {
                continue;
            }
            
            if (low[edge] == -1) {
                dfs(graph, low, curr, res, edge, currV);
                if (currV-1 < low[edge]) {
                    res.push_back({curr, edge});
                }
            }
            
            low[curr] = std::min(low[edge], low[curr]);
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        std::vector<std::vector<int> > res;
        if (n <= 1 || connections.empty()) {
            return res;
        }
        
        std::vector<int> low(n+1, -1);
        std::vector<std::vector<int> > graph(n+1, std::vector<int>(0));
        for (const auto conn : connections) {
            graph[conn[0]].push_back(conn[1]);
            graph[conn[1]].push_back(conn[0]);
        }
        
        low[0] = 0;
        dfs(graph, low, -1, res, 0, 0);
        return res;
    }
};
