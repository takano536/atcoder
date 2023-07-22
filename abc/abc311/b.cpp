#include <iostream>
#include <string>
#include <vector>

int main() {
    int n, d;
    std::cin >> n >> d;

    std::vector<std::string> s(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }

    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < d; i++) {
        bool satisfied = true;
        for (int j = 0; j < n; j++) {
            if (s[j][i] == 'x') {
                satisfied = false;
                break;
            }
        }
        if (satisfied) {
            cnt++;
        } else {
            ans = std::max(ans, cnt);
            cnt = 0;
        }
    }

    std::cout << std::max(ans, cnt) << std::endl;
    return 0;
}