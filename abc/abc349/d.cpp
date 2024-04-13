#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

int main() {
    long long l, r;
    std::cin >> l >> r;

    std::vector<long long> two_powers;
    long long curr = 1;
    while (curr <= r) {
        two_powers.push_back(curr);
        curr *= 2;
    }

    std::vector<std::pair<long long, long long>> asc;
    auto left = l;
    while (left < r) {
        auto curr = left;
        auto cnt = 0LL;
        while (curr % 2 == 0 && curr != 0) {
            curr /= 2;
            cnt++;
        }
        std::size_t offset;
        for (offset = 0; offset < two_powers.size() - 1; offset++) {
            if (two_powers[cnt + offset + 1] * (curr) != left || two_powers[cnt + offset + 1] * (curr + 1) > r) {
                break;
            }
        }
        asc.push_back({two_powers[cnt + offset] * curr, two_powers[cnt + offset] * (curr + 1)});
        left = asc.back().second;
        // std::cout << asc.back().first << " " << asc.back().second << std::endl;
    }

    // std::cout << "----" << std::endl;

    if (asc.back().second == r) {
        std::cout << asc.size() << std::endl;
        for (const auto &[l, r] : asc) {
            std::cout << l << " " << r << std::endl;
        }
        return 0;
    }
    asc.pop_back();

    std::vector<std::pair<long long, long long>> desc;
    auto right = r;
    while (right != asc.back().second && right != l) {
        auto curr = right;
        auto cnt = 0LL;
        while (curr % 2 == 0 && curr != 0) {
            curr /= 2;
            cnt++;
        }
        std::size_t offset;
        for (offset = 0; offset < two_powers.size() - 1; offset++) {
            if (two_powers[cnt + offset + 1] * (curr) != right || two_powers[cnt + offset + 1] * (curr - 1) < l) {
                break;
            }
        }
        desc.push_back({two_powers[cnt + offset] * (curr - 1), two_powers[cnt + offset] * curr});
        right = desc.back().first;
        // std::cout << desc.back().first << " " << desc.back().second << std::endl;
    }

    std::ranges::reverse(desc);
    std::cout << desc.size() + asc.size() << std::endl;
    for (const auto &[l, r] : asc) {
        std::cout << l << " " << r << std::endl;
    }
    for (const auto &[l, r] : desc) {
        std::cout << l << " " << r << std::endl;
    }
    return 0;
}