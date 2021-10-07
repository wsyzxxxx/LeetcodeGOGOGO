#include <bits/stdc++.h>
typedef long long LL;

long long n, t, s;

void solve() {
    std::priority_queue<long long> pq;

    long long base = 10;
    long long num = 1;
    while (s) {
        while (s % base != 0) {
            //std::cout << "inloop2" << " " << s % base  << " " << s << " " << num << " " << base << std::endl;
            s -= num;
            pq.push(-num);
        }
        num = base;
        base *= 10;
    }

    std::vector<long long> result;
    while (result.size() + pq.size() < n) {
        if (pq.top() == -1) {
            result.push_back(1);
            pq.pop();
        } else {
            int num = -pq.top();
            pq.pop();
            for (int i = 0; i < 10; i++) {
                pq.push(-(num/10));
            }
        }
    }

    while (result.size() + pq.size() > n) {
        long long num1 = -pq.top();
        pq.pop();
        long long num2 = -pq.top();
        pq.pop();
        pq.push(-(num1 + num2));
    }

    while (!pq.empty()) {
        result.push_back(-pq.top());
        pq.pop();
    }

    std::cout << result[0];
    for (int i = 1; i < result.size(); i++) {
        std::cout << " " << result[i];
    }
    std::cout << std::endl;
}

int main() {
    std::cin >> t;

    while (t--) {
        std::cin >> s >> n;
        solve();
    }

    return EXIT_SUCCESS;
}