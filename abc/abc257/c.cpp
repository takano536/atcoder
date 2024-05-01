#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    std::set<int> w;
    std::map<int, int> child_cnts, adult_cnts;
    for (int i = 0; i < n; i++) {
        int wi;
        std::cin >> wi;
        w.insert(wi);
        (s[i] == '0' ? child_cnts[wi] : adult_cnts[wi])++;
    }

    std::vector<int> child_cumsum(w.size() + 1), adult_cumsum(w.size() + 1);
    auto child_iter = child_cnts.begin();
    auto adult_iter = adult_cnts.begin();
    for (int i = 0; const auto &wi : w) {
        child_cumsum[i + 1] = child_cumsum[i] + (child_iter->first == wi ? child_iter->second : 0);
        adult_cumsum[i + 1] = adult_cumsum[i] + (adult_iter->first == wi ? adult_iter->second : 0);
        if (child_iter->first == wi && child_iter != child_cnts.end()) {
            child_iter++;
        }
        if (adult_iter->first == wi && adult_iter != adult_cnts.end()) {
            adult_iter++;
        }
        i++;
    }

    int ans = 0;
    for (std::size_t i = 0; i <= w.size(); i++) {
        ans = std::max(ans, child_cumsum[i] + adult_cumsum[w.size()] - adult_cumsum[i]);
    }

    std::cout << ans << std::endl;
    return 0;
}