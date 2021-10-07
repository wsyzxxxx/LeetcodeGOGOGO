#include <bits/stdc++.h>
typedef unsigned long long ULL;

int n, T;
std::string row;

void solve() {
    std::string res;

    for (int i = 0; i < n; i++) {
        if (row[i] == 'U') {
            res += "D";
        } else if (row[i] == 'D') {
            res += "U";
        } else {
            res += row[i];
        }
    }

    std::cout << res << std::endl;
}

int main() {
    std::cin >> T;

    while (T--) {
        std::cin >> n;
        std::cin >> row;

        solve();
    }

    return EXIT_SUCCESS;
}