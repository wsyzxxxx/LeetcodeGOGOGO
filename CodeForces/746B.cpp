#include <bits/stdc++.h>
typedef long long LL;

long long n, t, x;

void solve() {
    std::vector<std::pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> v[i].first;
        v[i].second = i;
    }

    std::sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        if (v[i].second != i && v[v[i].second].first != v[i].first) {
            if (i - x < 0 && i + x >= n || v[i].second - x < 0 && v[i].second + x >= n) {
                std::cout << "NO" << std::endl;
                return;
            }
        }
    }

    std::cout << "YES" << std::endl;
}

int main() {
    std::cin >> t;

    while (t--) {
        std::cin >> n >> x;
        solve();
    }

    return EXIT_SUCCESS;
}