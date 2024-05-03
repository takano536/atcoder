#include <iostream>
#include <utility>
#include <vector>

int main() {
    int n, x, y;
    std::cin >> n >> x >> y;

    auto f = [x, y](auto f, int lv, long long r, long long b) -> long long {
        return lv == 1 ? b : f(f, lv - 1, r + b + r * x, (b + r * x) * y);
    };

    std::cout << f(f, n, 1LL, 0LL) << std::endl;
}