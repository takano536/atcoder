#include <iostream>
#include <vector>

int main() {
    constexpr int LEN = 46;

    int n;
    std::cin >> n;

    std::vector<int> a(LEN), b(LEN), c(LEN);
    auto input = [&n](std::vector<int> &array) {
        for (int i = 0; i < n; i++) {
            int num;
            std::cin >> num;
            array[num % LEN]++;
        }
    };
    input(a), input(b), input(c);

    long long ans = 0;
    for (int i = 0; i < LEN; i++) {
        for (int j = 0; j < LEN; j++) {
            int k = (LEN - (i + j) % LEN) % LEN;
            ans += static_cast<long long>(a[i]) * b[j] * c[k];
        }
    }

    std::cout << ans << std::endl;
    return 0;
}