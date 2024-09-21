#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> h(n);
    for (auto &hi : h) std::cin >> hi;

    std::vector<int> heights;

    std::vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--) {
        ans[i] = heights.size();
        while (heights.size() > 0 && h[i] > heights.back()) heights.pop_back();
        heights.push_back(h[i]);
    }

    for (const auto &num : ans) std::cout << num << ' ';
    std::cout << std::endl;

    return 0;
}