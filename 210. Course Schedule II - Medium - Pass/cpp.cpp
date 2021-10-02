class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        std::vector<int> preqs(numCourses);
        std::vector<std::vector<int>> courses(numCourses);
        for (const auto & prereq : prerequisites) {
            preqs[prereq[0]]++;
            courses[prereq[1]].push_back(prereq[0]);
        }
        
        std::vector<int> result;
        std::queue<int> q;
        for (int i = 0; i < preqs.size(); i++) {
            if (preqs[i] == 0) {
                q.push(i);
            }
        }
        
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            
            result.push_back(course);
            
            for (int i = 0; i < courses[course].size(); i++) {
                if (--preqs[courses[course][i]] == 0) {
                    q.push(courses[course][i]);
                }
            }
        }
        
        if (result.size() < numCourses) {
            return {};
        }
        return result;
    }
};