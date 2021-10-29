#include <bits/stdc++.h>
typedef long long LL;

LL T;
std::string input;

void solve() {
    if (input.size() < 2) {
        std::cout << input << std::endl;
        return;
    }

    int ab = 0;
    int ba = 0;
    for (int i = 0; i < input.size()-1; i++) {
        if (input[i] == 'a' && input[i+1] == 'b') {
            ab++;
        } else if (input[i] == 'b' && input[i+1] == 'a') {
            ba++;
        }
    }

    if (ab == ba) {
        std::cout << input << std::endl;
    } else if (ab > ba) {
        input.back() = 'a';
        std::cout << input << std::endl;
    } else {
        input.back() = 'b';
        std::cout << input << std::endl;
    }
}

int main() {
    std::cin >> T;

    while (T--) {
        std::cin >> input;
        solve();
    }

    return EXIT_SUCCESS;
}