#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    std::string stack;
    for (auto c : s) {
        if (c == ')' && !stack.empty() && stack.back() == '(') {
            stack.pop_back();
        } else if (c == ']' && !stack.empty() && stack.back() == '[') {
            stack.pop_back();
        } else if (c == '>' && !stack.empty() && stack.back() == '<') {
            stack.pop_back();
        } else {
            stack += c;
        }
    }

    std::cout << (stack.empty() ? "Yes" : "No") << std::endl;
    return 0;
}