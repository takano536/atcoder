#include <iostream>
#include <string>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> pow_3(7);
    pow_3[0] = 1;
    for (int i = 1; i < 7; i++) {
        pow_3[i] = pow_3[i - 1] * 3;
    }

    std::vector<std::string> curr = {"#"};
    for (int i = 1; i <= n; i++) {
        std::vector<std::string> next(pow_3[i]);
        for (int j = 0; j < 9; j++) {
            for (int k = 0; k < curr.size(); k++) {
                next[j / 3 * curr.size() + k] += (j != 4 ? curr[k] : std::string(curr.size(), '.'));
            }
        }
        curr = next;
    }

    for (const auto &s : curr) {
        std::cout << s << std::endl;
    }
    return 0;
}