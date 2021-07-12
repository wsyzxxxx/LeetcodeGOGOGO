class Solution {
public:
    bool isRobotBounded(string instructions) {
        if (instructions.find('G') == std::string::npos) {
            return true;
        }
        
        int x = 0, y = 0;
        int face = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < instructions.size(); j++) {
                if (instructions[j] == 'G') {
                    switch (face) {
                        case 0: x++; break;
                        case 1: y++; break;
                        case 2: x--; break;
                        case 3: y--; break;
                        default: break;
                    }
                } else if (instructions[j] == 'L') {
                    face++;
                } else {
                    face--;
                }
                if (face == 4) {
                    face = 0;
                } else if (face == -1) {
                    face = 3;
                }
                //std::cout << x << " " << y << " " << face << std::endl;
            }
            
            if (x == 0 && y == 0 && face == 0) {
                return true;
            }
        }
        
        return false;
    }
};