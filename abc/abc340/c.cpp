#include <cmath>
#include <iostream>
#include <map>
#include <vector>

std::map<long long, long long> memo;

long long pay(long long n) {
    if (n == 1) {
        return 0;
    }
    if (memo.contains(n)) {
        return memo[n];
    }
    return memo[n] = n + pay(std::floor(static_cast<long double>(n) / 2)) + pay(std::ceil(static_cast<long double>(n) / 2));
}

int main() {
    long long n;
    std::cin >> n;

    std::cout << pay(n) << std::endl;
    return 0;
}