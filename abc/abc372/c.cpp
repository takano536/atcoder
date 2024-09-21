#include <iostream>
#include <string>
#include <vector>

int main() {
    int n, q;
    std::cin >> n >> q;

    std::string s;
    std::cin >> s;

    std::vector is_substr(n, std::vector<bool>(3));
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') is_substr[i][0] = true;
        if (s[i] == 'B' && i > 0 && is_substr[i - 1][0]) is_substr[i][1] = true;
        if (s[i] == 'C' && i > 0 && is_substr[i - 1][1]) is_substr[i][2] = true, ans++;
    }

    while (q--) {
        int x;
        char c;
        std::cin >> x >> c;
        x--;
        if (s[x] != c) {
            switch (c) {
                case 'A':
                    if (x + 2 >= 0 && x + 2 < n && s[x + 1] == 'B' && s[x + 2] == 'C') ans++;
                    break;
                case 'B':
                    if (x - 1 >= 0 && s[x - 1] == 'A' && x + 1 < n && s[x + 1] == 'C') ans++;
                    break;
                case 'C':
                    if (x - 2 >= 0 && s[x - 1] == 'B' && s[x - 2] == 'A') ans++;
                    break;
            }
            switch (s[x]) {
                case 'A':
                    if (x + 2 >= 0 && x + 2 < n && s[x + 1] == 'B' && s[x + 2] == 'C') ans--;
                    break;
                case 'B':
                    if (x - 1 >= 0 && s[x - 1] == 'A' && x + 1 < n && s[x + 1] == 'C') ans--;
                    break;
                case 'C':
                    if (x - 2 >= 0 && s[x - 1] == 'B' && s[x - 2] == 'A') ans--;
                    break;
            }
        }
        s[x] = c;
        std::cout << ans << std::endl;
    }
    return 0;
}