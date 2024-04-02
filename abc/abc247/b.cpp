#include <iostream>
#include <set>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::string> s(n), t(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i] >> t[i];
    }

    bool is_satisfied = true;
    for (int i = 0; i < n; i++) {
        std::set<std::string> names;
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            names.insert(s[j]);
            names.insert(t[j]);
        }
        if (names.contains(s[i]) && names.contains(t[i])) {
            is_satisfied = false;
            break;
        }
    }

    std::cout << (is_satisfied ? "Yes" : "No") << std::endl;
    return 0;
}