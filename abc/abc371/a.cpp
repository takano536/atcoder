#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<char> s(3);
    for (auto &si : s) std::cin >> si;

    std::vector<int> n = {0, 1, 2};
    do {
        bool is_satisfied = true;
        for (int i = 0; i < 3; i++) {
            switch (i) {
                case 0: {
                    auto a_iter = std::find(n.begin(), n.end(), 0);
                    auto b_iter = std::find(n.begin(), n.end(), 1);
                    if (s[i] == '>' && a_iter < b_iter) {
                        is_satisfied = false;
                    } else if (s[i] == '<' && a_iter > b_iter) {
                        is_satisfied = false;
                    }
                    break;
                }

                case 1: {
                    auto a_iter = std::find(n.begin(), n.end(), 0);
                    auto c_iter = std::find(n.begin(), n.end(), 2);
                    if (s[i] == '>' && a_iter < c_iter) {
                        is_satisfied = false;
                    } else if (s[i] == '<' && a_iter > c_iter) {
                        is_satisfied = false;
                    }
                    break;
                }

                case 2: {
                    auto b_iter = std::find(n.begin(), n.end(), 1);
                    auto c_iter = std::find(n.begin(), n.end(), 2);
                    if (s[i] == '>' && b_iter < c_iter) {
                        is_satisfied = false;
                    } else if (s[i] == '<' && b_iter > c_iter) {
                        is_satisfied = false;
                    }
                }
            }
        }

        if (is_satisfied) {
            std::cout << static_cast<char>(n[1] + 'A') << std::endl;
            return 0;
        }
    } while (std::next_permutation(n.begin(), n.end()));

    return -1;
}