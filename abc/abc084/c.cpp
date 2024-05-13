#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> c(n - 1), s(n - 1), f(n - 1);
    for (int i = 0; i < n - 1; i++) {
        std::cin >> c[i] >> s[i] >> f[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int t = c[i] + s[i];
        for (int j = i + 1; j < n - 1; j++) {
            t = std::max(((t + f[j] - 1) / f[j]) * f[j], s[j]);
            t += c[j];
        }
        std::cout << t << std::endl;
    }

    std::cout << 0 << std::endl;
    return 0;
}