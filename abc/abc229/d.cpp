#include <cassert>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

int main() {
    std::string s;
    int k;
    std::cin >> s >> k;

    const int n = s.size();
    int curr_k = k;
    int curr_len = 0;
    int ans = 0;
    std::queue<int> que;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'X') {
            curr_len++;
            ans = std::max(ans, curr_len);
            continue;
        }
        if (k == 0) {
            curr_len = 0;
            continue;
        }

        que.push(i);

        if (curr_k > 0) {
            curr_k--;
            curr_len++;
            ans = std::max(ans, curr_len);
            continue;
        }

        curr_len = i - que.front();
        assert(!que.empty());
        que.pop();
        ans = std::max(ans, curr_len);
    }

    std::cout << ans << std::endl;
    return 0;
}