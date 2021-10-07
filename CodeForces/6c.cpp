#include <bits/stdc++.h>
typedef long long LL;

long long n, t;
long long dp[11][2];

void solve() {
    std::vector<int> num;
    while (n) {
        num.push_back(n % 10);
        n /= 10;
    }
    if (num.size() == 1) {
        std::cout << num[0] - 1 << std::endl;
        return;
    }
    if (num.size() == 2) {
        int sum1 = num[0] + 1;
        int sum2 = num[1] + 1;

        std::cout << sum1 * sum2 - 2 << std::endl;
        return;
    }

    std::memset(dp, 0, sizeof(dp));
    for (int i = 0; i < num.size(); i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                int withCarry = i < 2 ? 0 : dp[i-2][1];
                int withoutCarry = i < 2 ? 1 : dp[i-2][0];
                if (j + k == num[i]) {
                    dp[i][0] += withoutCarry;
                }
                if (j + k + 1 == num[i]) {
                    dp[i][0] += withCarry;
                }
                if (j + k == num[i] + 10) {
                    dp[i][1] += withoutCarry;
                }
                if (j + k + 1 == num[i] + 10) {
                    dp[i][1] += withCarry;
                }
            }
        }
    }

    std::cout << dp[num.size()-1][0] * dp[num.size()-2][0] - 2 << std::endl;
}

int main() {
    std::cin >> t;

    while (t--) {
        std::cin >> n;
        solve();
    }

    return EXIT_SUCCESS;
}