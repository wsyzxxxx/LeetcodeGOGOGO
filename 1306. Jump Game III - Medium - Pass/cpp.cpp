class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if (arr.size() < 2) {
            return true;
        }
        
        std::queue<int> q;
        std::vector<bool> visited(arr.size(), false);
        q.push(start);
        visited[start] = true;
        int count = 1;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            
            if (arr[curr] == 0) {
                return true;
            }
            
            if (curr - arr[curr] >= 0 && !visited[curr - arr[curr]]) {
                count++;
                q.push(curr - arr[curr]);
                visited[curr - arr[curr]] = true;
            }
            
            if (curr + arr[curr] < arr.size() && !visited[curr + arr[curr]]) {
                count++;
                q.push(curr + arr[curr]);
                visited[curr + arr[curr]] = true;
            }
        }

        return false;
    }
};
