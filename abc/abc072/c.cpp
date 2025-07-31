#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    constexpr int MAX_A = 1e5;

    int n;
    std::cin >> n;

    std::vector<int> counts(MAX_A + 3);
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        a++;
        counts[a - 1]++, counts[a]++, counts[a + 1]++;
    }

    std::cout << *std::ranges::max_element(counts) << std::endl;
    return 0;
}