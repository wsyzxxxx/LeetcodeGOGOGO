int dp[302][30][30];

class Solution {
private:
    int getPosX(char ch) {
        return (ch - 'A') % 6;
    }
    int getPosY(char ch) {
        return (ch - 'A') / 6;
    }
    int getDist(char a, char b) {
        int ax = getPosX(a);
        int bx = getPosX(b);
        int ay = getPosY(a);
        int by = getPosY(b);
        return abs(ax - bx) + abs(ay - by);
    }
public:
    int minimumDistance(string word) {
        if (word.size() <= 1) {
            return 0;
        }
        
        std::memset(dp, -1, sizeof(dp));
        dp[0][26][26] = 0;
        
        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];
            
            for (int j = 0; j <= 26; j++) {
                for (int k = 0; k <= 26; k++) {
                    if (dp[i][j][k] == -1) {
                        continue;
                    }
                    
                    int dist1 = (j == 26) ? 0 : getDist(j+'A', ch);
                    dp[i+1][ch-'A'][k] = (dp[i+1][ch-'A'][k] == -1 || dp[i][j][k] + dist1 < dp[i+1][ch-'A'][k]) ? 
                        dp[i][j][k] + dist1 : dp[i+1][ch-'A'][k];
                    
                    int dist2 = (k == 26) ? 0 : getDist(k+'A', ch);
                    dp[i+1][j][ch-'A'] = (dp[i+1][j][ch-'A'] == -1 || dp[i][j][k] + dist2 < dp[i+1][j][ch-'A']) ? 
                        dp[i][j][k] + dist2 : dp[i+1][j][ch-'A'];
                    //std::cout << ch << " " << dist1 << " " << dist2 << std::endl;
                }
            }
        }
        
        int res = -1;
        for (int i = 0; i <= 26; i++) {
            for (int j = 0; j <= 26; j++) {
                if (dp[word.size()][i][j] == -1) {
                    continue;
                }
                //std::cout << dp[word.size()][i][j] << std::endl;
                if (res == -1 || res > dp[word.size()][i][j]) {
                    res = dp[word.size()][i][j];
                }
            }
        }
        
        return res;
    }
};
