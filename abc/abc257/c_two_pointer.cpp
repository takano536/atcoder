#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    std::vector<std::pair<int, bool>> w(n);
    for (int i = 0; auto &[wi, is_child] : w) {
        std::cin >> wi;
        is_child = s[i++] == '0';
    }

    std::ranges::sort(w);

    int fx = 0;
    for (const auto &[_, is_child] : w) {
        fx += !is_child;
    }

    int ans = fx;
    for (const auto &[_, is_child] : w) {
        fx += (is_child ? 1 : -1);
        ans = std::max(fx, ans);
    }

    std::cout << ans << std::endl;
    return 0;
}