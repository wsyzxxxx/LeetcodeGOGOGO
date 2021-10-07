#include <bits/stdc++.h>
typedef unsigned long long ULL;

ULL n, m;
std::vector<int> nums;
std::unordered_map<int, int> mp;

void solve() {
    for (int i = 0; i < n; i++) {
        mp[nums[i]] = i;
    }

    
}

int main() {
    std::cin >> n >> m;
    nums = std::vector<int>(n);
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }



    solve();

    return EXIT_SUCCESS;
}