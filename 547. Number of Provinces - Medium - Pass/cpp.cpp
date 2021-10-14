int parent[205];

int search(int x) {
    if (parent[x] != x) {
        parent[x] = search(parent[x]);
    }
    
    return parent[x];
}

void conn(int x, int y) {
    parent[search(x)] = search(y);    
}

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        std::memset(parent, 0, sizeof(parent));
        for (int i = 0; i < isConnected.size(); i++) {
            parent[i] = i;
        }
        
        for (int i = 0; i < isConnected.size(); i++) {
            for (int j = 0; j < isConnected[i].size(); j++) {
                if (isConnected[i][j] == 1) {
                    if (search(i) != search(j)) {
                        conn(i, j);
                    }
                }
            }
        }
        
        int count = 0;
        for (int i = 0; i < isConnected.size(); i++) {
            if (parent[i] == i) {
                count++;
            }
        }
        
        return count;
    }
};