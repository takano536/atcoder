#include <iostream>
#include <vector>

int main() {
    int n;
    long long m;
    std::cin >> n >> m;

    std::vector<int> a(n);
    long long a_sum = 0;
    for (auto &ai : a) {
        std::cin >> ai;
        a_sum += ai;
    }

    if (a_sum <= m) {
        std::cout << "infinite" << std::endl;
        return 0;
    }

    long long ok = 0;
    long long ng = 1e18;
    while (ng - ok > 1) {
        long long mid = (ok + ng) / 2;
        long long fee = 0;
        for (const auto &ai : a) {
            fee += std::min<long long>(ai, mid);
        }
        (fee <= m ? ok : ng) = mid;
    }

    std::cout << ok << std::endl;
    return 0;
}