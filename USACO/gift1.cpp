/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: wsyzxxx1
PROG: gift1
TASK: gift1
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    string name;
    string names[15];
    unordered_map<string, long> friends;
    int n;
    fin >> n;
    for (int i = 0; i < n; ++i) {
        fin >> name;
        names[i] = name;
        friends.insert(friends.end(), pair<string, long>(name, 0));
    }

    for (int i = 0; i < n; ++i) {
        fin >> name;
        int money, num, amount;
        fin >> money >> num;
        if (num)
            amount = money / num;
        else
            amount = 0;
        friends[name] -= amount * num;
        for (int j = 0; j < num; j++) {
            fin >> name;
            friends[name] += amount;
        }
    }

    unordered_map<string, long>::iterator it = friends.begin();
    for (int i = 0; i < n; ++i) {
        fout << names[i] << " " << friends[names[i]] << endl;
        it++;
    }

    return 0;
}
