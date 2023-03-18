#include <iostream>
#include <vector>

int main()
{
    int n, k;
    std::cin >> n >> k;
    std::vector<int> p(n), q(n);
    for (auto &num : p) {
        int input;
        std::cin >> input;
        num = input;
    }
    for (auto &num : q) {
        int input;
        std::cin >> input;
        num = input;
    }

    bool exists = false;
    for (const auto &num_p : p) {
        for (const auto &num_q : q) {
            if (num_p + num_q == k) {
                exists = true;
            }
        }
    }

    std::cout << (exists ? "Yes" : "No") << std::endl;
}