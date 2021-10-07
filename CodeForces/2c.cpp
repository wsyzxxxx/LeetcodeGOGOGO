#include <bits/stdc++.h>
typedef unsigned long long ULL;

ULL N, T;
ULL q;
std::string str;
std::vector<std::string> inputs;

bool cmp(const std::pair<int, std::string> & a, const std::pair<int, std::string> & b) {
    return a.second < b.second;
}

bool findSolution(std::stack<std::pair<std::string, int>> & pres,
                  std::stack<std::pair<std::string, int>> & sufs,
                  std::vector<bool> & isPre,
                  int index) {
    if (index == inputs.size()) {
        return true;
    }

    if (pres.empty() || pres.top().first.find(inputs[index]) != std::string::npos)
}
void solve() {
    std::vector<std::pair<int, std::string>> pres(inputs.size());
    for (int i = 0; i < inputs.size(); i++) {
        pres[i] = std::make_pair(i, inputs[i]);
    }
    std::vector<std::pair<int, std::string>> sufs(inputs.size());
    for (int i = 0; i < inputs.size(); i++) {
        std::string s = inputs[i];
        std::reverse(s.begin(), s.end());
        sufs[i] = std::make_pair(i, s);
    }

    std::sort(pres.begin(), pres.end(), cmp);
    std::sort(sufs.begin(), sufs.end(), cmp);

    std::vector<bool> isPre(inputs.size());

    
}

int main() {
    std::cin >> N;

    while (N--) {
        std::cin >> str;
        inputs.push_back(str);
    }

    solve();

    return EXIT_SUCCESS;
}