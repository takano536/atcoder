#include <iostream>
#include <set>
#include <vector>

int main() {
    int n;
    long long s;
    std::cin >> n >> s;

    std::vector<int> a(n * 2);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        a[i + n] = a[i];
    }

    n *= 2;
    std::vector<long long> cumsum(n + 1);
    for (int i = 0; i < n; i++) cumsum[i + 1] = cumsum[i] + a[i];

    auto rem = s % cumsum[n / 2];
    std::set<long long> rem_left_sum;
    for (int i = 0; i < n; i++) rem_left_sum.insert(cumsum[i] + rem);

    for (const auto &right : cumsum) {
        if (rem_left_sum.contains(right)) {
            std::cout << "Yes" << std::endl;
            return 0;
        }
    }

    std::cout << "No" << std::endl;
    return 0;
}