#include <bits/stdc++.h>
typedef unsigned long long ULL;

const ULL MOD = 998244353ULL;
int n;
bool hasNum;
std::vector<int> nums;

void solve() {
    
}

int main() {
    std::cin >> n;
    nums = std::vector<int>(n);
    hasNum = false;
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
        if (nums[i] != -1) {
            hasNum = true;
        }
    }

    solve();

    return EXIT_SUCCESS;
}