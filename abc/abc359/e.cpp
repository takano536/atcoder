#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> h(n);
    for (auto &hi : h) std::cin >> hi;

    std::vector<int> height, width;
    long long curr = 0;
    for (const auto &hi : h) {
        long long wi = 1;
        while (!height.empty() && !width.empty() && hi > height.back()) {
            long long h_top = height.back();
            long long w_top = width.back();
            wi += w_top;
            curr -= h_top * w_top;
            height.pop_back();
            width.pop_back();
        }
        height.push_back(hi);
        width.push_back(wi);
        curr += static_cast<long long>(height.back()) * width.back();
        std::cout << curr + 1 << ' ';
    }
    std::cout << std::endl;
    return 0;
}