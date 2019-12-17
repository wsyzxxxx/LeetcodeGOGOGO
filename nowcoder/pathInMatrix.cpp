class Solution {
private:
    bool checkPath(char* matrix, int rows, int cols, char* str, 
                   int curr, int i, int j, bool path[]) {
        if (str[curr] == '\0') {
            return true;
        }
        if (i < 0 || j < 0 || i >= rows || j >= cols || path[i*cols+j]) {
            return false;
        }
        if (matrix[i*cols+j] == str[curr]) {
            //std::cout << "check: " << str[curr] << std::endl;
            path[i*cols+j] = true;
            bool res = checkPath(matrix, rows, cols, str, curr+1, i-1, j, path) ||
                       checkPath(matrix, rows, cols, str, curr+1, i, j-1, path) ||
                       checkPath(matrix, rows, cols, str, curr+1, i, j+1, path) ||
                       checkPath(matrix, rows, cols, str, curr+1, i+1, j, path);
            if (res) {
                return res;
            } else {
                path[i*cols+j] = false;
                return res;
            }
        } else {
            return false;
        }
    }
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if (matrix == NULL || str == NULL) {
            return false;
        }
        
        bool * path = new bool[rows*cols];
        for (int i = 0; i < rows*cols; i++) {
            path[i] = false;
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (checkPath(matrix, rows, cols, str, 0, i, j, path)) {
                    return true;
                }
            }
        }
        return false;
    }


};
