#include <bits/stdc++.h>

int n, k;
bool nodes[4][105];

void init() {
    std::memset(nodes, 0, sizeof(nodes));
}

void output() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < n; j++) {
            if (nodes[i][j]) {
                printf("#");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

void solve() {
    if (k == 0) {
        printf("YES\n");
        output();
        return;
    }

    if (k % 2 == 0) {
        for (int i = 1; k > 0; i++, k -= 2) {
            nodes[1][i] = true;
            nodes[2][i] = true;
        }
        printf("YES\n");
        output();
        return;
    }

    nodes[1][n/2] = true;
    k--;
    for (int i = 1; n/2 - i > 0 && k > 0; i++, k -= 2) {
        nodes[1][n/2-i] = true;
        nodes[1][n/2+i] = true;
    }
    for (int i = 1; k > 0; i++, k -= 2) {
        nodes[2][i] = true;
        nodes[2][n-1-i] = true;
    }
    printf("YES\n");
    output();
}

int main(void) {
    init();

    scanf("%d %d", &n, &k);
    solve();
}
