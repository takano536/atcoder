#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

int main() {
    int n, q;
    std::cin >> n >> q;

    std::vector<int> a(n), idxes(n);
    std::iota(a.begin(), a.end(), 0);
    std::iota(idxes.begin(), idxes.end(), 0);

    for (int i = 0; i < q; i++) {
        int x;
        std::cin >> x;
        x--;

        auto left_iter = a.begin() + idxes[x];
        auto right_iter = *left_iter == a.back() ? std::prev(left_iter) : std::next(left_iter);
        std::swap(idxes[x], idxes[*right_iter]);
        std::iter_swap(left_iter, right_iter);
    }

    for (const auto &ai : a) {
        std::cout << ai + 1 << ' ';
    }
    std::cout << std::endl;
    return 0;
}