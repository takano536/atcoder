#include <deque>
#include <iostream>
#include <string>

#include <atcoder/modint>

int main() {
    int q;
    std::cin >> q;

    atcoder::modint998244353 ans = 1;
    std::deque<char> s = {'1'};
    int s_len = 1;
    for (int i = 0; i < q; i++) {
        int query;
        std::cin >> query;

        switch (query) {
            case 1: {
                char x;
                std::cin >> x;
                s_len++;
                ans *= 10;
                ans += static_cast<int>(x - '0');
                s.push_back(x);
                break;
            }
            case 2: {
                s_len--;
                ans -= atcoder::modint998244353(10).pow(s_len) * static_cast<int>(s[0] - '0');
                s.pop_front();
                break;
            }
            case 3: {
                std::cout << ans.val() << std::endl;
                break;
            }
        }
    }
    return 0;
}