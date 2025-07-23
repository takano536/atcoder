#include <iostream>
#include <queue>
#include <string>

void solve() {
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;
    s = static_cast<std::string>("0") + s;

    std::queue<int> que;
    que.push(0);
    std::vector<bool> has_visited(s.size());

    while (!que.empty()) {
        const auto sv = que.front();
        que.pop();

        for (int i = 0; i < n; i++) {
            const auto nv = sv | (1 << i);
            if (has_visited[nv]) continue;
            if (s[nv] == '1') continue;
            has_visited[nv] = true;
            que.push(nv);
        }
    }

    std::cout << (has_visited[(1 << n) - 1] ? "Yes" : "No") << '\n';
}

int main() {
    int t;
    std::cin >> t;

    while (t--) solve();

    std::cout << std::flush;
    return 0;
}