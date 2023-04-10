#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (auto &price : a) {
        std::cin >> price;
    }

    std::set<long long> prices;
    for (const auto &price : a) {
        prices.insert(price);
    }

    auto price_iter = std::min_element(prices.begin(), prices.end());
    for (int i = 0; i < k; i++) {
        for (const auto &price : a) {
            prices.insert(*price_iter + price);
        }
        price_iter++;
    }

    auto ans_iter = prices.begin();
    for (int i = 0; i < k - 1; i++) {
        ans_iter++;
    }

    std::cout << *ans_iter << std::endl;
    return 0;
}