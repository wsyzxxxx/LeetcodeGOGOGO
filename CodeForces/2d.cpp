#include <bits/stdc++.h>
typedef unsigned long long ULL;

ULL N, T;
ULL q;
std::string steps;

ULL root, rootLevel;
ULL currNum, currLevel;
std::stack<ULL> s;

ULL findNum(ULL num) {
    ULL curr = root;
    ULL currLevel = rootLevel;
    while (curr != num) {
        s.push(curr);
        if (num < curr) {
            curr -= currLevel;
        } else {
            curr += currLevel;
        }
        currLevel /= 2;
    }
    s.push(curr);

    return currLevel;
}

void solve() {
    root = (N + 1) / 2;
    rootLevel = root / 2;

    ULL currLevel = findNum(q);
    ULL currNum = q;

    for (int i = 0; i < steps.size(); i++) {
        if (steps[i] == 'U') {
            s.pop();
            currLevel = currLevel == 0 ? 1 : currLevel * 2;
            if (s.empty()) {
                s.push(root);
                currLevel = rootLevel;
            }
        } else if (steps[i] == 'L') {
            if (currLevel == 0) {
                continue;
            }
            s.push(s.top() - currLevel);
            currLevel /= 2;
        } else {
            if (currLevel == 0) {
                continue;
            }
            s.push(s.top() + currLevel);
            currLevel /= 2;
        }
    }

    std::cout << s.top() << std::endl;

    while (!s.empty()) {
        s.pop();
    }
}

int main() {
    std::cin >> N >> T;

    while (T--) {
        std::cin >> q;
        std::cin >> steps;

        solve();
    }

    return EXIT_SUCCESS;
}