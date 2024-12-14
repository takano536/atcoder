#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

int main() {
    constexpr int N = 5;

    std::array<int, N> scores;
    for (auto &score : scores) std::cin >> score;

    std::vector<std::pair<int, std::string>> prob_ids;
    for (int bit = 0; bit < (1 << N); bit++) {
        std::vector<int> probs;
        for (int i = 0; i < N; i++) {
            if (bit & (1 << i)) probs.push_back(i);
        }

        int total = 0;
        for (const auto &i : probs) total += scores[i];

        std::string id;
        for (const auto &i : probs) id += 'A' + i;

        prob_ids.push_back(std::make_pair(-total, id));
    }

    std::ranges::sort(prob_ids);
    for (const auto &[_, ans] : prob_ids) std::cout << ans << std::endl;
    return 0;
}