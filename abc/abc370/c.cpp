#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string s, t;
    std::cin >> s >> t;

    const int n = s.size();

    int big_count = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] > t[i]) big_count++;
    }

    std::vector<std::string> x;
    while (s != t) {
        if (big_count > 0) {
            for (int i = 0; i < n; i++) {
                if (s[i] == t[i]) continue;
                if (s[i] < t[i]) continue;
                s[i] = t[i];
                big_count--;
                break;
            }
        } else {
            for (int i = n - 1; i >= 0; i--) {
                if (s[i] == t[i]) continue;
                s[i] = t[i];
                break;
            }
        }
        x.push_back(s);
    }

    std::cout << x.size() << std::endl;
    for (const auto &xi : x) std::cout << xi << std::endl;

    return 0;
}