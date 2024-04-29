#include <cassert>
#include <iostream>
#include <map>

int main() {
    int q;
    std::cin >> q;

    std::map<int, int> s;

    for (int query = 0; query < q; query++) {
        int opt;
        std::cin >> opt;

        switch (opt) {
            case 1: {
                int x;
                std::cin >> x;
                s[x]++;
                break;
            }
            case 2: {
                int x, c;
                std::cin >> x >> c;
                s[x] -= std::min(c, s[x]);
                if (s[x] == 0) {
                    s.erase(x);
                }
                break;
            }
            case 3: {
                std::cout << s.rbegin()->first - s.begin()->first << std::endl;
                break;
            }
            default: {
                assert(false);
            }
        }
    }

    return 0;
}