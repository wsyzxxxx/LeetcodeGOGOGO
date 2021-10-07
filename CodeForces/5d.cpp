#include <bits/stdc++.h>
typedef long long LL;

const LL MOD = 1e9+7;
int n;
std::vector<int> nums;

LL dp[100005];

void solve() {
    std::memset(dp, 0, sizeof(dp));

    dp[0] = 1;
    for (int i = 0; i < nums.size(); i++) {
        int num = nums[i];

        if (num == 1) {
            dp[1]++;
            continue;
        }

        for (int j = std::min((int)std::sqrt(num), (int)i+1); j > 0; j--) {
            if (num % j == 0) {
                int k = num / j;
                if (k > j && k <= nums.size()) {
                    dp[k] = (dp[k] + dp[k-1]) % MOD;
                }
                dp[j] = (dp[j] + dp[j-1]) % MOD;
            }
        }
        
    }

    LL sum = 0;
    for (int j = 1; dp[j] != 0; j++) {
        sum = (sum + dp[j]) % MOD;
    }

    std::cout << sum << std::endl;
}

int main() {
    std::cin >> n;

    nums = std::vector<int>(n);
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }

    solve();

    return EXIT_SUCCESS;
}