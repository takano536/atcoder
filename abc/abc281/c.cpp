#include <iostream>
#include <utility>
#include <vector>

int main() {
    int n;
    long long t;
    std::cin >> n >> t;

    long long total = 0;
    std::vector<int> a(n);
    for (auto &ai : a) std::cin >> ai, total += ai;

    t %= total;

    std::pair<int, long long> ans;
    for (int i = 0; i < n; i++) {
        t -= a[i];
        if (t < 0) {
            auto &[id, time] = ans;
            id = i + 1;
            time = t + a[i];
            break;
        }
    }

    const auto &[id, time] = ans;
    std::cout << id << ' ' << time << std::endl;
    return 0;
}