#include <bits/stdc++.h>
typedef long long LL;

LL n, l, x, y;
LL a;
std::unordered_set<LL> st;

void solve() {
    //0
    int remain = 3;
    for (const LL num : st) {
        if (st.count(num - x) || st.count(num + x)) {
            remain = remain & 1;
        }
        if (st.count(num - y) || st.count(num + y)) {
            remain = remain & 2;
        }
    }

    if (remain == 0) {
        std::cout << 0 << std::endl;
        return;
    } else if (remain == 1) {
        std::cout << 1 << std::endl;
        std::cout << y << std::endl;
        return;
    } else if (remain == 2) {
        std::cout << 1 << std::endl;
        std::cout << x << std::endl;
        return;
    }

    LL res = - 1;
    for (const LL num : st) {
        LL dest = num + x;
        if (dest < l && (st.count(dest - y) || st.count(dest + y))) {
            res = dest;
            break;
        }
        dest = num - x;
        if (dest > 0 && (st.count(dest - y) || st.count(dest + y))) {
            res = dest;
            break;
        }
    }

    if (res != -1) {
        std::cout << 1 << std::endl;
        std::cout << res << std::endl;
        return;
    }

    std::cout << 2 << std::endl;
    std::cout << x << " " << y << std::endl;
}

int main() {
    std::cin >> n >> l >> x >> y;
    st.clear();

    for (int i = 1; i <= n; i++) {
        std::cin >> a;
        st.insert(a);
    }

    solve();

    return EXIT_SUCCESS;
}