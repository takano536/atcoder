#include <iostream>
#include <stdexcept>
#include <string>

int main() {
    int n;
    std::cin >> n;

    int i_min = 1;
    int i_max = n;
    while (i_max - i_min > 0) {
        int mid = (i_max + i_min) / 2;

        std::cout << "? ";
        std::cout << i_min << ' ';
        std::cout << mid << ' ';
        std::cout << 1 << ' ';
        std::cout << n << ' ';
        std::cout << std::endl;

        int t;
        std::cin >> t;
        if (t == -1) throw std::runtime_error("WA");

        int t_max = mid - i_min + 1;
        if (t != t_max) {
            i_max = mid;
        } else {
            i_min = mid + 1;
        }
        if (i_min > i_max) std::swap(i_max, i_min);
    }

    int j_min = 1;
    int j_max = n;
    while (j_max - j_min > 0) {
        int mid = (j_max + j_min) / 2;

        std::cout << "? ";
        std::cout << 1 << ' ';
        std::cout << n << ' ';
        std::cout << j_min << ' ';
        std::cout << mid;
        std::cout << std::endl;

        int t;
        std::cin >> t;
        if (t == -1) throw std::runtime_error("WA");

        int t_max = mid - j_min + 1;
        if (t != t_max) {
            j_max = mid;
        } else {
            j_min = mid + 1;
        }
        if (j_min > j_max) std::swap(j_max, j_min);
    }
    std::cout << "! " << std::to_string(i_min) + ' ' << std::to_string(j_min) << std::endl;
    return 0;
}