#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> peoples(n);
    for (auto &[_, p] : peoples) std::cin >> p, p--;
    for (auto &[q, _] : peoples) std::cin >> q, q--;

    auto sorted_peoples = peoples;
    std::sort(sorted_peoples.begin(), sorted_peoples.end());

    for (const auto &[_, eye] : sorted_peoples) {
        const auto &[id, __] = peoples[eye];
        std::cout << id + 1 << ' ';
    }
    std::cout << std::endl;

    return 0;
}