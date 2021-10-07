#include <bits/stdc++.h>
typedef unsigned long long ULL;

int n;
std::string a, b;
std::string strs[] = {"aa", "ab", "ac", "ba", "bb", "bc", "ca", "cb", "cc"};
std::string cand[] = {"abc", "acb", "bac", "bca", "cab", "cba"};

void solve() {
    std::cout << "YES" << std::endl;
    if (n == 1) {
        for (int i = 0; i < 6; i++) {
            std::string res = cand[i];
            if (res.find(a) == res.npos && res.find(b) == res.npos) {
                std::cout << res << std::endl;
                return;
            }
        }
        return;
    }

    for (int i = 0; i < 6; i++) {
        std::string can = cand[i];
        can += cand[i];
        if (can.find(a) == can.npos && can.find(b) == can.npos) {
            std::string ans = can;
            for (int k = 2; k < n - 1; k += 2) {
                ans += can;
            }
            if (n & 1) {
                ans += cand[i];
            }
            std::cout << ans << std::endl;
            return;
        }
    }

    std::string c1 = "a";
    std::string c2 = "b";
    std::string c3 = "c";
    std::string cc1, cc2, cc3;
    for (int i = 0; i < n; i++) {
        cc1 += c1;
        cc2 += c2;
        cc3 += c3;
    }

    std::unordered_set<std::string> st;
    st.insert(a);
    st.insert(b);

    std::string res;
    //std::cout << a << " " << b << std::endl;
    if (st.count("ab") || st.count("ac")) {
        //std::cout << "has ab" << std::endl;
        if (st.count("ba") || st.count("cb")) {
            res = cc2 + cc3 + cc1;
        } else {
            res = cc3 + cc2 + cc1;
        }
    } else if (st.count("ba") || st.count("bc")) {
        if (st.count("ab") || st.count("ca")) {
            res = cc1 + cc3 + cc2;
        } else {
            res = cc3 + cc1 + cc2;
        }
    } else {
        if (st.count("ab")) {
            res = cc2 + cc1 + cc3;
        } else {
            res = cc1 + cc2 + cc3;
        }
    }
    std::cout << res << std::endl;
}

int main() {
    std::cin >> n;
    std::cin >> a >> b;

    solve();

    return EXIT_SUCCESS;
}