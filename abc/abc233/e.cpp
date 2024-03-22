#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <vector>

int main() {
    std::string x;
    std::cin >> x;
    int n = x.size();

    std::vector<int> cumsum(n + 1);
    for (int i = 0; i < n; i++) {
        cumsum[i + 1] = cumsum[i] + x[i] - '0';
    }

    std::string ans;
    std::list<std::string> carryings;
    for (int i = 0; i < n; i++) {
        int curr = cumsum[n - i] - cumsum[0];
        for (auto &carrying : carryings) {
            if (carrying.size() == 0) {
                continue;
            }
            curr += carrying.back() - '0';
            carrying.pop_back();
        }
        while (carryings.size() > 0 && carryings.front().size() == 0) {
            carryings.pop_front();
        }
        std::string curr_string = std::to_string(curr);
        ans += curr_string.back();
        curr_string.pop_back();
        carryings.push_back(curr_string);
    }

    int curr = 0;
    for (auto &carrying : carryings) {
        if (carrying.size() == 0) {
            continue;
        }
        curr += carrying.back() - '0';
        carrying.pop_back();
    }
    if (curr > 0) {
        ans += std::to_string(curr);
    }
    std::ranges::reverse(ans);
    std::cout << ans << std::endl;
    return 0;
}