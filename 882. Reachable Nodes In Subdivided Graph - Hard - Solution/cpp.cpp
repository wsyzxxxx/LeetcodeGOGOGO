class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        std::vector<std::vector<std::pair<int, int>>> graph(n);
        
        for (const auto & edge : edges) {
            graph[edge[0]].push_back({edge[1], edge[2] + 1});
            graph[edge[1]].push_back({edge[0], edge[2] + 1});
        }
        
        std::priority_queue<std::pair<long long, int>> pq;
        std::vector<long long> reachable(n, -1);
        pq.push({0, 0});
        reachable[0] = 0;

        while (!pq.empty()) {
            int node = pq.top().second;
            long long dist = -pq.top().first;
            pq.pop();
            
            for (const auto & next : graph[node]) {
                //std::cout << next.second + dist << " " << maxMoves << std::endl;
                if (next.second + dist <= maxMoves && 
                    (reachable[next.first] == -1 || next.second + dist <= reachable[next.first])) {
                    reachable[next.first] = next.second + dist;
                    pq.push({-(dist+next.second), next.first});
                }
            }
        }
        
        int count = 1;
        for (const auto & edge : edges) {
            long long dist1 = reachable[edge[0]] == -1 ? std::numeric_limits<int>::max() : reachable[edge[0]];
            long long dist2 = reachable[edge[1]] == -1 ? std::numeric_limits<int>::max() : reachable[edge[1]];
            long long minDist = std::min(dist1, dist2);
            if (minDist == std::numeric_limits<int>::max()) {
                continue;
            }
            
            if (minDist + edge[2] <= maxMoves) {
                count += edge[2];
            } else {
                int count0 = std::max(0LL, maxMoves-dist1);
                int count1 = std::max(0LL, maxMoves-dist2);
                count += std::min(edge[2], count0 + count1);
            }
            //std::cout << reachable[edge[0]] << " " << reachable[edge[1]] << " " << count << std::endl;
        }
        
        for (int i = 1; i < n; i++) {
            if (reachable[i] > 0) {
                count++;
            }
        }
        
        return count;
    }
};