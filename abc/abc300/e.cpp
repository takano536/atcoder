#include <iostream>
#include <map>

#include <atcoder/modint>

int main() {
    long long n;
    std::cin >> n;

    std::map<long long, atcoder::modint> memo;
    auto calc = [n, &memo](auto &&f, long long x) -> atcoder::modint {
        if (x == n) return 1;
        if (x > n) return 0;
        if (memo.contains(x)) return memo[x];

        atcoder::modint ret = 0;
        for (int i = 2; i <= 6; i++) ret += f(f, x * i);

        ret /= 5;
        memo[x] = ret;
        return ret;
    };

    std::cout << calc(calc, 1).val() << std::endl;
    return 0;
}