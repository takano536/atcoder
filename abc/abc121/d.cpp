#include <iostream>

long long f(long long x) {
    long long ret = 0;
    long long pow = 2;
    int bit = 0;

    while (pow / 2 <= x) {
        long long bit_count = 0;

        auto chunk_size = (x + 1) / pow;
        bit_count += chunk_size * (pow / 2);

#ifdef _DEBUG
        std::cout << "pow: " << pow << std::endl;
        std::cout << "chunk_size: " << chunk_size << std::endl;
        std::cout << "bit_count: " << bit_count << std::endl;
#endif

        auto snippet_size = (x + 1) % pow;
        bit_count += snippet_size > pow / 2 ? (x + 1) % (pow / 2) : 0;
#ifdef _DEBUG
        std::cout << "snippet_size: " << snippet_size << std::endl;
        std::cout << "bit_count: " << bit_count << std::endl;
#endif

        if (bit_count % 2) ret ^= 1LL << bit;

        bit++, pow *= 2;
    }

    return ret;
}

int main() {
    long long a, b;
    std::cin >> a >> b;

    std::cout << (f(a - 1) ^ f(b)) << std::endl;
    // std::cout << f(a - 1) << ' ' << f(b) << std::endl;
    return 0;
}