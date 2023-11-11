#include <iostream>
#include <string>
#include <vector>

int main() {
    int n, q;
    std::cin >> n >> q;

    std::string s;
    std::cin >> s;

    std::vector<int> l(q), r(q);
    for (int i = 0; i < q; i++) {
        std::cin >> l[i] >> r[i];
        l[i]--, r[i]--;
    }

    std::vector<int> cumsum(n);
    for (int i = 1; i < n; i++) {
        cumsum[i] = cumsum[i - 1] + static_cast<int>(s[i - 1] == s[i]);
    }

    for (int i = 0; i < q; i++) {
        std::cout << cumsum[r[i]] - cumsum[l[i]] << std::endl;
    }
    return 0;
}