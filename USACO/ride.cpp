/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: wsyzxxx1
PROG: ride 
TASK: ride
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string comet, group;
    fin >> comet >> group;
    int cometValue = 1;
    int groupValue = 1;
    for (size_t i = 0; i < comet.size(); ++i)
    	cometValue = cometValue * (comet[i] - 'A' + 1) % 47;
    for (size_t i = 0; i < group.size(); ++i)
    	groupValue = groupValue * (group[i] - 'A' + 1) % 47;
    if (cometValue == groupValue)
    	fout << "GO" << endl;
    else
    	fout << "STAY" << endl;
    return 0;
}
