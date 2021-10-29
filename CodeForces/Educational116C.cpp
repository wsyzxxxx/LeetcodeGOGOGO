#include <bits/stdc++.h>
typedef long long LL;

LL T, K, N;
int a;
std::unordered_set<int> st;

void solve() {
    LL count = 0;
    LL curr = 0;

    LL base = 1;
    while (count < K) {
        if (st.count(curr)) {
            count += 9;
            base = 1;
        } else {
            base *= 10;
            count += 9 * base;
        }
        curr++;
    }
    curr--;

    std::string res;
    base = 1;
    LL acc = 1;
    count = 0;
    for (LL i = 0; i <= curr; i++) {
        if (st.count(i)) {
            acc /= 10;
            while (base > 1) {
                res = "9" + res;
                base--;
                count += acc * 9;
                acc /= 10;
            }
            acc = 1;
        }
        base++;
        acc *= 10;
    }

    //std::cout << res.empty() << std::endl;
    //acc = res.empty() ? 0 : std::stoll(res);
    if (count < K) {
        //std::cout << curr << std::endl;
        //std::cout << K-count << std::endl;
        if (st.count(curr)) {
            res = (char)((K - count) + '0') + res;
        } else {
            res = std::to_string(K - count) + res;
        }
    }

    std::cout << res << std::endl;
}

int main() {
    std::cin >> T;

    while (T--) {
        st.clear();
        std::cin >> N >> K;
        K++;
        for (int i = 0; i < N; i++) {
            std::cin >> a;
            st.insert(a);
        }
        solve();
    }

    return EXIT_SUCCESS;
}