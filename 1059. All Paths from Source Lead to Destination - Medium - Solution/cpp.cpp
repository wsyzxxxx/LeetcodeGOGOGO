class Solution {
private:
    bool dfs(std::vector<int> & visitedStatus, std::vector<std::vector<int>> & graph, int curr, int dest) {
        if (visitedStatus[curr] != 0) {
            return visitedStatus[curr] == 2;
        }
        if (graph[curr].empty()) {
            visitedStatus[curr] = 2;
            return curr == dest;
        }
        
        visitedStatus[curr] = 1;
        
        for (int i = 0; i < graph[curr].size(); i++) {
            if (!dfs(visitedStatus, graph, graph[curr][i], dest)) {
                return false;
            }
        }
        
        visitedStatus[curr] = 2;
        
        return true;
    }
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        std::vector<std::vector<int>> graph(n);
        
        for (const auto & edge : edges) {
            graph[edge[0]].push_back(edge[1]);
        }
        
        if (graph[destination].size() > 0) {
            return false;
        }
        
        std::vector<int> visitedStatus(n, 0);

        return dfs(visitedStatus, graph, source, destination);
        //     for (int i = 0; i < n; i++) {
        //         if (visitedStatus[i] != 2) {
        //             return false;
        //         }
        //     }
        //     return true;
        // } else {
        //     return false;
        // }
    }
};