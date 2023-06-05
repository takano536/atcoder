#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
    const int MAX_SCORE = 300;
    const int TERM = 3;

    int n, k;
    std::cin >> n >> k;
    k--;

    std::vector<int> p(n);
    for (auto &total : p) {
        std::vector<int> scores(TERM);
        for (auto &score : scores) {
            std::cin >> score;
        }
        total = std::accumulate(scores.begin(), scores.end(), 0);
    }

    auto sorted_p = p;
    std::sort(sorted_p.rbegin(), sorted_p.rend());

    for (const auto &total : p) {
        std::cout << ((total + MAX_SCORE) >= sorted_p[k] ? "Yes" : "No") << std::endl;
    }
    return 0;
}