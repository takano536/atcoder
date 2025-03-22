#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    constexpr int N = 7;

    std::vector<int> cnts(16);
    for (int i = 0; i < N; ++i) {
        int a;
        std::cin >> a;
        cnts[a]++;
    }

    std::ranges::sort(cnts);

    bool exists_pair = false;
    for (const auto &cnt : cnts) {
        if (cnt >= 2) {
            exists_pair = true;
            cnts.erase(std::find(cnts.begin(), cnts.end(), cnt));
            break;
        }
    }

    if (!exists_pair) {
        std::cout << "No" << std::endl;
        return 0;
    }

    for (const auto &cnt : cnts) {
        if (cnt >= 3) {
            std::cout << "Yes" << std::endl;
            return 0;
        }
    }

    std::cout << "No" << std::endl;
    return 0;
}