#include <bits/stdc++.h>
typedef unsigned long long ULL;

const ULL MOD = 998244353ULL;
int n;
int a, b;
std::vector<std::pair<int, int>> nums;

bool cmp(const std::pair<int, std::pair<int, int>> & a, const std::pair<int, std::pair<int, int>> & b) {
    if (a.second.first == b.second.first) {
        return a.second.second < b.second.second;
    }
    return a.second.first < b.second.first;
}

void solve() {
    std::priority_queue<int> pq;
    std::vector<std::pair<int, std::pair<int, int>>> numPairs(n);
    for (int i = 0; i < n; i++) {
        numPairs[i] = {i, nums[i]};
    }
    std::sort(numPairs.begin(), numPairs.end(), cmp);

    std::vector<int> results(n, 0);
    for (int i = 0; i < n; i++) {
        
    }

    for (int i = 0; i < n; i++) {
        std::cout << results[i] << std::endl;
    }
}

int main() {
    std::cin >> n;
    nums = std::vector<std::pair<int, int>>(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a >> b;
        if (a > b) {
            std::swap(a, b);
        }
        nums[i] = std::make_pair(a, b);
    }

    solve();

    return EXIT_SUCCESS;
}