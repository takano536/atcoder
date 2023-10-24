#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string s;
    std::cin >> s;

    std::vector<bool> exists(26);
    std::string box;
    std::vector<int> right_bracket_idxs;
    for (int i = 0; const auto &c : s) {
        box.push_back(c);
        if (c == '(') {
            right_bracket_idxs.push_back(i);
        } else if (c == ')' && right_bracket_idxs.size() > 0) {
            int bracket_idx = *std::prev(right_bracket_idxs.end());
            right_bracket_idxs.pop_back();
            while (i > bracket_idx) {
                char tail = *std::prev(box.end());
                if (tail != '(' && tail != ')') {
                    exists[tail - 'a'] = false;
                }
                box.pop_back();
                i--;
            }
        } else if (exists[c - 'a']) {
            std::cout << "No" << std::endl;
            return 0;
        } else {
            exists[c - 'a'] = true;
        }
        i++;
    }
    std::cout << "Yes" << std::endl;
}