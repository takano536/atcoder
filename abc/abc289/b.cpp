#include <algorithm>
#include <iostream>
#include <stack>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(m);
    for (auto &num : a) {
        std::cin >> num;
        num--;
    }

    std::stack<int> pending_list;
    std::vector<int> ans;
    int a_idx = 0;
    for (int i = 0; i < n; i++) {
        if (a.size() > 0 && i == a[a_idx]) {
            pending_list.push(i + 1);
            a_idx++;
        } else {
            ans.push_back(i + 1);
            while (!pending_list.empty()) {
                ans.push_back(pending_list.top());
                pending_list.pop();
            }
        }
    }

    for (const auto &num : ans) {
        std::cout << num << ' ';
    }
    std::cout << std::endl;
}