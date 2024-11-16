#include <iostream>
#include <string>
#include <utility>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;
    k--;

    std::string s;
    std::cin >> s;

    std::vector<std::pair<int, int>> intervals;
    std::pair<int, int> interval{-1, -1};
    bool is_interval = false;
    for (int i = 0; i < n; i++) {
        if (!is_interval && s[i] == '1') {
            interval.first = i;
            is_interval = true;
        }
        if (is_interval && s[i] == '0') {
            interval.second = i - 1;
            intervals.push_back(interval);
            interval = {-1, -1};
            is_interval = false;
        }
    }
    if (is_interval) {
        interval.second = n - 1;
        intervals.push_back(interval);
    }

    int i = 0;
    int interval_idx = -1;
    auto [kth_head, kth_tail] = intervals[k];
    is_interval = false;
    while (i < n) {
        std::cout << s[i];
        if (!is_interval && s[i] == '1') {
            interval_idx++;
            is_interval = true;
        }
        if (is_interval && s[i] == '0') {
            is_interval = false;
        }

        if (interval_idx == k - 1 && is_interval) {
            if (i != n - 1 && s[i + 1] == '1') {
                i++;
                continue;
            }
            std::cout << std::string(kth_tail - kth_head + 1, '1');
            std::cout << std::string(kth_head - i - 1, '0');
            i = kth_tail + 1;
            interval_idx++;
            continue;
        }
        i++;
    }
    std::cout << std::endl;
    return 0;
}