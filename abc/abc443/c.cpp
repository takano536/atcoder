#include <iostream>
#include <vector>

int main() {
    constexpr int COOLTIME = 100;

    int n, t;
    std::cin >> n >> t;

    std::vector<int> a(n);
    for (auto &ai : a) std::cin >> ai;
    a.push_back(t);

    long long ans = 0;
    int next_opening_time = 0;
    for (const auto &ai : a) {
        if (ai < next_opening_time) continue;
        ans += ai - next_opening_time;
        next_opening_time = ai + COOLTIME;
    }

    std::cout << ans << std::endl;
    return 0;
}