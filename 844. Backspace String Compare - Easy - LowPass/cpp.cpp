class Solution {
private:
    int nextCharacter(std::string & str, int & index) {
        int count = 1;
        while (count > 0) {
            index--;
            if (index >= 0 && str[index] == '#') {
                count++;
            } else {
                count--;
            }
        }
        
        return index < 0 ? index : str[index];
    }
public:
    bool backspaceCompare(string S, string T) {
        int i = S.size();
        int j = T.size();
        
        while (nextCharacter(S, i) == nextCharacter(T, j) && i > -1 && j > -1) {
            //std::cout << i << " " << j << std::endl;
        }
        //std::cout << i << " " << j << std::endl;
        return ((i >= 0 && j >= 0) && (S[i] == T[j])) || (i < 0 && j < 0);
    }
};
