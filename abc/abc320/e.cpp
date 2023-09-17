#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> t(m), w(m), s(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> t[i] >> w[i] >> s[i];
    }

    std::set<int> lined_people;
    for (int i = 0; i < n; i++) {
        lined_people.insert(i);
    }

    std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<std::pair<long long, int>>> waiting_que;
    std::vector<long long> ans(n);

    for (int i = 0; i < m; i++) {
        while (!waiting_que.empty()) {
            auto wait_top = waiting_que.top();
            if (wait_top.first > t[i]) {
                break;
            }
            waiting_que.pop();
            lined_people.insert(wait_top.second);
        }

        if (lined_people.empty()) {
            continue;
        }
        auto top = *lined_people.begin();
        lined_people.erase(lined_people.begin());
        ans[top] += w[i];
        waiting_que.push(std::make_pair(t[i] + s[i], top));
    }

    for (int i = 0; i < n; i++) {
        std::cout << ans[i] << std::endl;
    }
}