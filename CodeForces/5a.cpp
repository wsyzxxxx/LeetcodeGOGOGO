#include <bits/stdc++.h>
typedef unsigned long long ULL;

int n;
int a, b;
std::unordered_map<int, std::pair<int, int>> mp;

void solve() {
    std::vector<int> result;

    int curr = 1;
    result.push_back(curr);
    while (result.size() < n) {
        int n1 = mp[curr].first;
        int n2 = mp[curr].second;

        if (mp[n1].first == n2 || mp[n1].second == n2) {
            result.push_back(n1);
            result.push_back(n2);
            curr = n2;
        } else {
            result.push_back(n2);
            result.push_back(n1);
            curr = n1;
        }
    }

    if (result.size() > n) {
        result.pop_back();
    }

    std::cout << result[0];
    for (int i = 1; i < n; i++) {
        std::cout << " " << result[i];
    }
    std::cout << std::endl;
}

int main() {
    std::cin >> n;
    mp.clear();

    for (int i = 1; i <= n; i++) {
        std::cin >> a >> b;
        mp[i] = {a, b};
    }

    solve();

    return EXIT_SUCCESS;
}