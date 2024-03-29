#include <iostream>
#include <queue>
#include <set>
#include <string>

int main() {
    int n = 3;
    std::string s, t;
    for (int i = 0; i < n; i++) {
        char c;
        std::cin >> c;
        s += c;
    }
    for (int i = 0; i < n; i++) {
        char c;
        std::cin >> c;
        t += c;
    }

    std::set<std::string> ans;
    std::set<std::string> caps;
    std::queue<std::string> que;
    ans.insert(s);
    caps.insert(s);
    que.push(s);
    int i = 0;
    while (!que.empty()) {
        i++;
        auto cap = que.front();
        que.pop();
        for (int lhs = 0; lhs < n; lhs++) {
            for (int rhs = 0; rhs < n; rhs++) {
                if (lhs == rhs) {
                    continue;
                }
                auto next = cap;
                std::swap(next[lhs], next[rhs]);
                if (caps.contains(next)) {
                    continue;
                }
                caps.insert(next);
                que.push(next);
                if (i % 2 == 0) {
                    ans.insert(next);
                }
            }
        }
    }

    std::cout << (ans.contains(t) ? "Yes" : "No") << std::endl;
    return 0;
}