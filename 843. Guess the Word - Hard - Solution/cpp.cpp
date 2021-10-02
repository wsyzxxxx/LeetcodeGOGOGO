/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
private:
    int matchX(const std::string & a, const std::string & b) {
        int count = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == b[i]) {
                count++;
            }
        }
        
        return count;
    }
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {  
        std::random_device dev;
        std::mt19937 rng(dev());
        for (int i = 1; i <= 10; i++) {
            std::uniform_int_distribution<std::mt19937::result_type> dist(0, wordlist.size()-1);
            std::string word = wordlist[dist(rng)];
            
            int x = master.guess(word);
            std::cout << x <<std::endl;
            if (x < 6) {
                std::vector<std::string> nextlist;
                for (int j = 0; j < wordlist.size(); j++) {
                    if (matchX(word, wordlist[j]) == x) {
                        nextlist.push_back(wordlist[j]);
                    }
                }
                
                wordlist = nextlist;
            } else {
                break;
            }
        }
    }
};