#include <iostream>
#include <map>

int main() {
    long long n;
    std::cin >> n;

    std::map<long long, long long> memo;
    memo[0] = 1;

    auto f = [&](auto f, long long x) -> long long {
        if (x == 0) return memo[0];
        if (!memo.contains(x / 2)) memo[x / 2] = f(f, x / 2);
        if (!memo.contains(x / 3)) memo[x / 3] = f(f, x / 3);
        return memo[x / 2] + memo[x / 3];
    };

    std::cout << f(f, n) << std::endl;
    return 0;
}