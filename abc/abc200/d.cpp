#include <iostream>
#include <string>
#include <vector>

#include <atcoder/modint>

int main() {
    const int MOD = 200;
    atcoder::modint::set_mod(MOD);

    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto &ai : a) {
        std::cin >> ai;
    }

    const int max_len = std::min(n, 8);
    std::vector seq_ids(MOD, std::vector<int>());
    for (int bit = 1; bit < (1 << max_len); bit++) {
        atcoder::modint mod;
        for (int i = 0; i < max_len; i++) {
            if (bit & (1 << i)) {
                mod += a[i];
            }
        }
        seq_ids[mod.val()].push_back(bit);
    }

    std::vector<int> b, c;
    for (int i = 0; i < MOD; i++) {
        if (seq_ids[i].size() < 2) {
            continue;
        }
        for (int j = 0; j < max_len; j++) {
            if (seq_ids[i][0] & (1 << j)) {
                b.push_back(j + 1);
            }
        }
        for (int j = 0; j < max_len; j++) {
            if (seq_ids[i][1] & (1 << j)) {
                c.push_back(j + 1);
            }
        }
        break;
    }

    if (b.size() == 0) {
        std::cout << "No" << std::endl;
        return 0;
    }
    std::cout << "Yes" << std::endl;
    std::cout << b.size() << ' ';
    for (const auto &num : b) {
        std::cout << num << ' ';
    }
    std::cout << std::endl;
    std::cout << c.size() << ' ';
    for (const auto &num : c) {
        std::cout << num << ' ';
    }
    std::cout << std::endl;
    return 0;
}