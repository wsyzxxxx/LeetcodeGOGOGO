#include <bits/stdc++.h>
typedef long long LL;

long long n, t, h;
long long w1, w2;

void solve() {
    w1 = w2 = -1;
    std::vector<LL> v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }

    std::sort(v.begin(), v.end());

    LL count = h / (v.back() + v[v.size()-2]) * 2;
    h -= (LL)(v.back() + v[v.size()-2]) * count / 2;
    if (h == 0) {
        std::cout << count << std::endl;
        return;
    }
    LL rest = h > v.back() ? 2 : 1;

    std::cout << count + rest << std::endl;
}

int main() {
    std::cin >> t;

    while (t--) {
        std::cin >> n >> h;
        solve();
    }

    return EXIT_SUCCESS;
}