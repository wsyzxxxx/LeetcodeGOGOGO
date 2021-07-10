int visited[55][55];

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        std::memset(visited, -1, sizeof(visited));
        
        std::priority_queue<std::pair<int, std::pair<int, int>>> pq;
        pq.push(std::make_pair(-grid[0][0], std::make_pair(0, 0)));
        
        int minDist = INT_MAX;
        while (!pq.empty()) {
            int currD = -pq.top().first;
            int currX = pq.top().second.first;
            int currY = pq.top().second.second;
            pq.pop();
            
            if (currD > minDist) {
                break;
            }
            if (visited[currX][currY] != -1 && visited[currX][currY] <= currD) {
                continue;
            }
            visited[currX][currY] = currD;
            if (currX == n-1 && currY == n-1) {
                minDist = std::min(currD, minDist);
            }
            
            if (currX > 0) {
                pq.push({-1 * std::max(currD, grid[currX-1][currY]), std::make_pair(currX-1, currY)});
            }
            if (currY > 0) {
                pq.push({-1 * std::max(currD, grid[currX][currY-1]), std::make_pair(currX, currY-1)});
            }
            if (currX < grid.size()-1) {
                pq.push({-1 * std::max(currD, grid[currX+1][currY]), std::make_pair(currX+1, currY)});
            }
            if (currY < grid[0].size()-1) {
                pq.push({-1 * std::max(currD, grid[currX][currY+1]), std::make_pair(currX, currY+1)});
            }            
        }
        
        return minDist;
    }
};