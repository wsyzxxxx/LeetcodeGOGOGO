#include <bits/stdc++.h>
typedef unsigned long long ULL;

int a, b, c, d;
int N;

void solve0() {
    std::cout << "YES\n1\n1\n3\n3" << std::endl;
}

bool check(std::vector<int> nums) {
    std::sort(nums.begin(), nums.end());

    int avg = (nums[0] + nums[1] + nums[2] + nums[3]) % 4 == 0 ? (nums[0] + nums[1] + nums[2] + nums[3]) / 4 : -1;
    int range = nums[3] - nums[0];
    int median = (nums[1] + nums[2]) % 2 == 0 ? (nums[1] + nums[2]) / 2 : -2;
    if (avg == range && range == median) {
        return true;
    } else {
        return false;
    }
}

void solve1() {
    std::cout << "YES" << std::endl;

    if (a & 1) {
        int b = a + 2;
        int median = a + 1;
        int c = median - median / 2;
        int d = median + median / 2;

        std::cout << c << std::endl;
        std::cout << b << std::endl;
        std::cout << d << std::endl;
    } else {
        int b = a + 4;
        int median = a + 2;
        int c = median - median / 2;
        int d = median + median / 2;

        std::cout << c << std::endl;
        std::cout << b << std::endl;
        std::cout << d << std::endl;
    }
}

void solve2() {
    std::vector<int> nums;
    nums.push_back(a);
    nums.push_back(b);
    nums.push_back(0);
    nums.push_back(0);

    for (int i = 1; i <= 2000; i++) {
        nums[2] = i;
        for (int j = 1; j <= 2000; j++) {
            nums[3] = j;
            if (check(nums)) {
                std::cout << "YES" << std::endl;
                std::cout << i << std::endl;
                std::cout << j << std::endl;
                return;
            }
        }
    }
    std::cout << "NO" << std::endl;
}

void solve3() {
    std::vector<int> nums;
    nums.push_back(a);
    nums.push_back(b);
    nums.push_back(c);
    nums.push_back(0);
    for (int i = 1; i <= 2000; i++) {
        nums[3] = i;

        if (check(nums)) {
            std::cout << "YES" << std::endl;
            std::cout << i << std::endl;
            return;
        }
    }
    std::cout << "NO" << std::endl;
}

void solve4() {
    std::vector<int> nums;
    nums.push_back(a);
    nums.push_back(b);
    nums.push_back(c);
    nums.push_back(d);

    if (check(nums)) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
}

int main() {
    std::cin >> N;
    if (N == 0) {
        solve0();
    }
    if (N == 1) {
        std::cin >> a;
        solve1();
    }
    if (N == 2) {
        std::cin >> a >> b;
        solve2();
    }
    if (N == 3) {
        std::cin >> a >> b >> c;
        solve3();
    }
    if (N == 4) {
        std::cin >> a >> b >> c >> d;
        solve4();
    }

    return EXIT_SUCCESS;
}