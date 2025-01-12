#include <algorithm>
#include <deque>
#include <iostream>
#include <stdexcept>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    std::deque<char> que;
    bool is_reverse = false;

    for (const auto &c : s) {
        switch (c) {
            case 'R':
                is_reverse = !is_reverse;
                break;

            default:
                if (std::isupper(c)) throw std::runtime_error("invalid S");
                if (que.empty()) {
                    is_reverse ? que.push_back(c) : que.push_front(c);
                    continue;
                }
                if (!is_reverse) que.back() == c ? que.pop_back() : que.push_back(c);
                if (is_reverse) que.front() == c ? que.pop_front() : que.push_front(c);
                break;
        }
    }

    if (is_reverse) std::ranges::reverse(que);
    for (const auto &c : que) std::cout << c;
    std::cout << std::endl;
    return 0;
}