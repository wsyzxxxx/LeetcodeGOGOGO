class Solution
{
private:
    int characters[256] = {0};
    int index = 1;
public:
  //Insert one char from stringstream
    void Insert(char ch)
    {
        if (characters[ch] == 0) {
            characters[ch] = index;
        } else if (characters[ch] > 0) {
            characters[ch] = -1;
        }
        index++;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        int minIndex = INT_MAX;
        int minIn = -1;
        for (int i = 0; i < 256; i++) {
            if (characters[i] > 0 && characters[i] < minIndex) {
                minIndex = characters[i];
                minIn = i;
            }
        }
        
        if (minIn != -1) {
            return (char)minIn;
        } else {
            return '#';
        }
    }

};
