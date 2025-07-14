#include <algorithm>
#include <iostream>
#include <numeric>
#include <set>
#include <string>

std::string to_base_n(const long long x, const int base) {
    const auto ret = std::to_string(x % base);
    return x >= base ? to_base_n(x / base, base) + ret : ret;
}

bool is_palindrome(const long long x, const int base = 10) {
    const auto str = to_base_n(x, base);
    auto reversed_str = str;
    std::ranges::reverse(reversed_str);
    return str == reversed_str;
}

int main() {
    int a;
    long long n;
    std::cin >> a >> n;

    std::set<long long> palindromes;
    for (int num = 1; num < 1e6; num++) {
        const auto num_str = std::to_string(num);
        auto reversed_num_str = num_str;
        std::ranges::reverse(reversed_num_str);

        const auto longer_num_str = num_str + reversed_num_str;
        const auto longer_num = std::stoll(longer_num_str);
        if (longer_num <= n && is_palindrome(longer_num, a)) palindromes.insert(longer_num);

        const auto shorter_num_str = num_str.substr(0, num_str.size() - 1) + reversed_num_str;
        const auto shorter_num = std::stoll(shorter_num_str);
        if (shorter_num <= n && is_palindrome(shorter_num, a)) palindromes.insert(shorter_num);
    }

    std::cout << std::accumulate(palindromes.begin(), palindromes.end(), 0LL) << std::endl;
    return 0;
}