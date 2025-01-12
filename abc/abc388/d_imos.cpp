#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (auto &ai : a) std::cin >> ai;

    std::vector<int> cumsum(n + 1);
    for (int i = 0; i < n; i++) {
        if (i > 0) cumsum[i] += cumsum[i - 1];
        const int get_num = cumsum[i];
        a[i] += get_num;

        const int max_give_num = n - i - 1;
        const int give_num = std::min(a[i], max_give_num);

        if (give_num > 0) {
            cumsum[i + 1]++;
            cumsum[i + give_num + 1]--;
        }

        a[i] -= give_num;
        std::cout << a[i] << ' ';
    }
    std::cout << std::endl;
    return 0;
}