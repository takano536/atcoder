#include <iostream>
#include <string>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::string> s(n);
    int max_len = 0;
    for (auto &si : s) {
        std::cin >> si;
        max_len = std::max<int>(max_len, si.size());
    }

    for (auto &si : s) si += std::string(max_len - si.size(), '*');

    std::vector<std::string> ans;
    for (int i = 0; i < max_len; i++) {
        std::string curr;
        for (int j = n - 1; j >= 0; j--) curr += s[j][i];
        while (curr.back() == '*') curr.pop_back();
        std::cout << curr << std::endl;
    }
    return 0;
}