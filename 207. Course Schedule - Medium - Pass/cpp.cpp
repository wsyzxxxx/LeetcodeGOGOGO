class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (numCourses <= 0) {
            return false;
        }
        // if (numCourses == 1) {
        //     return true;
        // }
        
        std::vector<int> in(numCourses, 0);
        std::vector<bool> visited(numCourses, false);
        std::unordered_map<int, std::vector<int> > mp;
        
        for (const auto pre : prerequisites) {
            mp[pre[0]].push_back(pre[1]);
            in[pre[1]]++;
        }
        
        std::queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (in[i] == 0) {
                visited[i] = true;
                q.push(i);
            }
        }
        
        int count = 0;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            count++;
            
            for (const auto i : mp[curr]) {
                in[i]--;
                if (in[i] == 0 && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        
        return (count == numCourses);
    }
};
