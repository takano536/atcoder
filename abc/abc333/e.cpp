#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> events(n);
    std::map<int, int> monsters;
    std::map<int, std::set<int>> potions;
    for (int i = 0; i < n; i++) {
        std::cin >> events[i].first >> events[i].second;
        if (events[i].first == 1) {
            potions[events[i].second].insert(-i);
        } else {
            monsters[events[i].second]++;
        }
    }

    std::set<int> used_potions;
    for (int i = n - 1; i >= 0; i--) {
        if (events[i].first == 1) {
            continue;
        }
        auto used_postions_iter = potions[events[i].second].upper_bound(-i);
        if (used_postions_iter == potions[events[i].second].end()) {
            std::cout << -1 << std::endl;
            return 0;
        }
        used_potions.insert(*used_postions_iter);
        potions[events[i].second].erase(used_postions_iter);
    }

    std::map<int, int> stocks;
    int stock_cnt = 0;
    int ans = 0;
    std::string actions;
    for (int i = 0; i < n; i++) {
        if (events[i].first == 1) {
            if (used_potions.contains(-i)) {
                stock_cnt++;
                stocks[events[i].second]++;
                actions += "1 ";
            } else {
                actions += "0 ";
            }
        }
        if (events[i].first == 2) {
            if (stocks[events[i].second] > 0) {
                stocks[events[i].second]--;
                stock_cnt--;
            } else {
                std::cout << -1 << std::endl;
                return 0;
            }
        }

        ans = std::max(ans, stock_cnt);
    }

    std::cout << ans << std::endl;
    std::cout << actions << std::endl;
    return 0;
}