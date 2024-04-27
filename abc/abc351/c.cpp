#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto &ai : a) {
        std::cin >> ai;
    }
    std::vector<int> stack;
    for (int i = 0; i < n; i++) {
        stack.push_back(a[i]);
        while (stack.size() >= 2) {
            int back = stack.back();
            int pre_back = stack[stack.size() - 2];
            if (back != pre_back) {
                break;
            }
            stack.pop_back();
            stack.pop_back();
            stack.push_back(back + 1);
        }
    }

    std::cout << stack.size() << std::endl;
    return 0;
}