#include <cassert>
#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {
    const int NA = -1;

    int n;
    std::string s;
    std::cin >> n >> s;

    std::map<int, int> heads, tails;  // top --- back
    heads[0] = NA;
    tails[0] = NA;

    for (int i = 1; i <= n; i++) {
        switch (s[i - 1]) {
            case 'R':
                heads[i] = i - 1;
                if (tails[i - 1] != NA) {
                    heads[tails[i - 1]] = i;
                }
                tails[i] = tails[i - 1];
                tails[i - 1] = i;
                break;
            case 'L':
                tails[i] = i - 1;
                if (heads[i - 1] != NA) {
                    tails[heads[i - 1]] = i;
                }
                heads[i] = heads[i - 1];
                heads[i - 1] = i;
                break;
            default:
                assert(false);
        }
    }

    std::vector<int> ans;
    int curr = NA;
    for (const auto &[key, value] : heads) {
        if (value == NA) {
            ans.push_back(key);
            curr = key;
            break;
        }
    }
    assert(curr != NA);

    while (tails[curr] != NA) {
        ans.push_back(tails[curr]);
        curr = tails[curr];
    }

    for (const auto &num : ans) {
        std::cout << num << ' ';
    }
    std::cout << std::endl;
    return 0;
}