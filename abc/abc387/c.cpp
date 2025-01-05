#include <iostream>
#include <string>

long long powll(long long base, long long exp) {
    long long ret = 1;
    for (long long i = 0; i < exp; i++) ret *= base;
    return ret;
}

long long floor4snake(long long n) {
    std::string n_str = std::to_string(n);
    int base = n / powll(10, n_str.size() - 1);
    std::string ret_str{n_str[0]};
    for (std::size_t i = 1; i < n_str.size(); i++) {
        if (n_str[i] - '0' >= base) {
            ret_str += '0' + base - 1;
            break;
        }
        ret_str += n_str[i];
    }
    if (ret_str.size() < n_str.size()) ret_str += std::string(n_str.size() - ret_str.size(), '0' + base - 1);
    return std::stoll(ret_str);
}

long long nbase2decimal(long long n, int base) {
    std::string n_str = std::to_string(n);
    long long ret = 0;
    for (std::size_t i = 0; i < n_str.size(); i++) {
        ret += (n_str[i] - '0') * powll(base, n_str.size() - i - 1);
    }
    return ret;
}

long long count_snake(long long n) {
    if (n < 10) return 0;

    n = floor4snake(n);
    int len = std::to_string(n).size();
    long long n_lower = n % powll(10, len - 1);

    long long ret = 0;
    int curr_base = 1;
    int curr_len = 2;
    while (true) {
        auto curr_str = std::to_string(curr_base) + std::string(curr_len - 1, '0' + curr_base - 1);
        auto curr = std::stoll(curr_str);
        auto curr_lower = curr % powll(10, curr_len - 1);
        ret += nbase2decimal((curr < n ? curr_lower : n_lower), curr_base) + 1;
        if (curr >= n) break;
        curr_base++;
        if (curr_base == 10) curr_base = 1, curr_len++;
    }
    return ret;
}

int main() {
    long long l, r;
    std::cin >> l >> r;
    std::cout << count_snake(r) - count_snake(l - 1) << std::endl;
    return 0;
}