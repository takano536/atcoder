#include <iostream>
#include <string>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    auto rec = [&n, &m](auto f, const std::string &seq) -> std::vector<std::string> {
        std::vector<std::string> res = {seq};
        for (int i = seq.back() - '0' + 1; i < m; i++) {
            auto seqs = f(f, seq + static_cast<char>('0' + i));
            for (const auto &s : seqs) res.push_back(s);
        }
        return res;
    };

    std::vector<std::string> ans;
    for (int i = 0; i < m; i++) {
        std::string s{static_cast<char>('0' + i)};
        auto seqs = rec(rec, s);
        for (const auto &seq : seqs) {
            if (seq.size() == static_cast<std::size_t>(n)) ans.push_back(seq);
        }
    }

    for (const auto &s : ans) {
        for (const auto &c : s) {
            int x = c - '0';
            std::cout << x + 1 << ' ';
        }
        std::cout << std::endl;
    }
    return 0;
}