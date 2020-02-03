int dist[102][102];

#define INF 1e9+7
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        if (n < 1 || edges.empty()) {
            return 0;
        }
        
        for (int i = 0; i < 102; i++) {
            for (int j = 0; j < 102; j++) {
                dist[i][j] = INF;
                dist[j][i] = INF;
            }
        }
        
        for (const auto edge : edges) {
            dist[edge[0]][edge[1]] = edge[2];
            dist[edge[1]][edge[0]] = edge[2];
        }
        
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        
        int res = 0;
        int minReach = std::numeric_limits<int>::max();
        for (int i = 0; i < n; i++) {
            int canReach = 0;
            for (int j = 0; j < n; j++) {
                if (dist[i][j] <= distanceThreshold && i != j) {
                    canReach++;
                }
            }
            //std::cout << canReach << std::endl;
            if (canReach <= minReach) {
                res = i;
                minReach = canReach;
            }
        }
        
        return res;
    }
};
