class Solution {
private:
    int calSum(int i, int j) {
        int sum = 0;
        while (i) {
            sum += i % 10;
            i /= 10;
        }
        while (j) {
            sum += j % 10;
            j /= 10;
        }
        return sum;
    }
    int checkMoving(int threshold, int rows, int cols,
                     int i, int j, bool * visited) {
        if (i >= 0 && i < rows && j >= 0 && j < cols &&
            calSum(i, j) <= threshold && !visited[i*cols+j]) {
            visited[i*cols+j] = true;
            return checkMoving(threshold, rows, cols, i, j-1, visited) +
                   checkMoving(threshold, rows, cols, i, j+1, visited) +
                   checkMoving(threshold, rows, cols, i-1, j, visited) +
                   checkMoving(threshold, rows, cols, i+1, j, visited) + 1;
        } else {
            return 0;
        }
    }
public:
    int movingCount(int threshold, int rows, int cols)
    {
        if (threshold < 0 || rows <= 0 || cols <= 0) {
            return 0;
        }
        
        bool * visited = new bool[rows*cols];
        for (int i = 0; i < rows*cols; i++) {
            visited[i] = false;
        }
        int res = checkMoving(threshold, rows, cols, 0, 0, visited);
        delete[] visited;
        return res;
    }
};
