#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string s, t;
    std::cin >> s >> t;

    std::vector<bool> is_front_match(s.size()), is_rear_match(s.size());
    is_front_match[0] = (s[0] == t[0] || s[0] == '?' || t[0] == '?');
    is_rear_match[s.size() - 1] = (s[s.size() - 1] == t[t.size() - 1] || s[s.size() - 1] == '?' || t[t.size() - 1] == '?');

    for (std::size_t i = 1; i < t.size(); i++) {
        if (s[i] != '?' && t[i] != '?' && s[i] != t[i]) {
            continue;
        }
        is_front_match[i] = is_front_match[i - 1];
    }

    for (std::size_t i = 1; i < t.size(); i++) {
        int s_idx = (s.size() - 1) - i;
        int t_idx = (t.size() - 1) - i;
        if (s[s_idx] != '?' && t[t_idx] != '?' && s[s_idx] != t[t_idx]) {
            continue;
        }
        is_rear_match[s_idx] = is_rear_match[s_idx + 1];
    }

    int front_idx = -1;
    int rear_idx = s.size() - t.size();
    for (int i = 0; i < static_cast<int>(t.size() + 1); i++, front_idx++, rear_idx++) {
        bool satisfies_front = false;
        bool satisfies_rear = false;

        if (front_idx >= 0) {
            satisfies_front = is_front_match[front_idx];
        } else {
            satisfies_front = true;
        }
        if (rear_idx < static_cast<int>(s.size())) {
            satisfies_rear = is_rear_match[rear_idx];
        } else {
            satisfies_rear = true;
        }

        std::cout << (satisfies_front && satisfies_rear ? "Yes" : "No") << std::endl;
    }
    return 0;
}