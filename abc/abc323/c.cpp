#include <algorithm>
#include <iostream>
#include <ranges>
#include <string>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::pair<int, int>> problems(m);
    for (int i = 0; i < m; i++) {
        std::cin >> problems[i].first;
        problems[i].second = i;
    }

    std::vector<std::pair<int, int>> scores(n);
    std::vector<std::string> s(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
        for (int j = 0; j < m; j++) {
            scores[i].first += s[i][j] == 'o' ? problems[j].first : 0;
        }
        scores[i].first += i + 1;
        scores[i].second = i;
    }

    std::ranges::sort(problems, std::greater<>());

    auto sorted_scores = scores;
    std::ranges::sort(sorted_scores, std::greater<>());
    auto max_score = sorted_scores[0];

    for (int i = 0; i < n; i++) {
        if (max_score.second == i) {
            std::cout << 0 << std::endl;
            continue;
        }

        int ans = 0;
        int curr_score = scores[i].first;
        for (int j = 0; j < m; j++) {
            if (s[i][problems[j].second] == 'o') {
                continue;
            }
            curr_score += problems[j].first;
            ans++;
            if (curr_score >= max_score.first) {
                break;
            }
        }
        std::cout << ans << std::endl;
    }
    return 0;
}