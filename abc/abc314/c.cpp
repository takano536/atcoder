#include <iostream>
#include <string>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::string s;
    std::cin >> s;

    std::vector<std::string> str(m);
    std::vector<int> str_size(m, -1);
    std::vector<int> c(n);
    for (int i = 0; i < n; i++) {
        std::cin >> c[i];
        c[i]--;
        str_size[c[i]]++;
        str[c[i]] += s[i];
    }

    std::vector<int> idxs = str_size;
    std::string ans;
    for (int i = 0; i < n; i++) {
        ans += str[c[i]][idxs[c[i]]];
        idxs[c[i]] = (idxs[c[i]] + 1) % str[c[i]].size();
    }

    std::cout << ans << std::endl;
    return 0;
}