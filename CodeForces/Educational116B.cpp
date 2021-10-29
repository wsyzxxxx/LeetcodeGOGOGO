#include <bits/stdc++.h>
typedef long long LL;

LL T, K, N;

void solve() {
    LL curr = 1;
    LL acc = 1;
    LL count = 0;
    while (acc < N && curr < K) {
        acc += curr;
        curr = std::min(acc, K);
        count++;
    }
    if (acc < N) {
        count += (N - acc) / curr + ((N - acc) % curr == 0 ? 0 : 1);
    }
    std::cout << count << std::endl;
}

int main() {
    std::cin >> T;

    while (T--) {
        std::cin >> N >> K;
        solve();
    }

    return EXIT_SUCCESS;
}