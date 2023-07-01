#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i] >> b[i];
    }

    std::vector<std::pair<long double, int>> probs(n);
    for (int i = 0; i < n; i++) {
        probs[i] = std::make_pair((long double)a[i] / (a[i] + b[i]), n - (i + 1));
    }

    std::sort(probs.rbegin(), probs.rend());

    for (int i = 0; i < n; i++) {
        std::cout << n - probs[i].second << ' ';
    }
    std::cout << std::endl;

    return 0;
}