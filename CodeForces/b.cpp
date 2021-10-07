#include <bits/stdc++.h>

long long n, k;
long long num, lcm;

long long gcd(long long a, long long b) {
    while (b) {
        long long temp = a % b;
        a = b;
        b = temp;
    }

    return a;
}

void solve() {
    //std::unordered_set<int> st;
    scanf("%d", &lcm);
    for (int i = 1; i < n; i++) {
        scanf("%d", &num);
        lcm = num * lcm / gcd(num, lcm);
        lcm %= k;
        //st.insert(num);
    }

    if (lcm % k == 0) {
        printf("Yes\n");
        return;
    }

    printf("No\n");
}

int main(void) {
    scanf("%d %d", &n, &k);
    
    solve();

    return EXIT_SUCCESS;
}