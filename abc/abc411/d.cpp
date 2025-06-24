#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <tuple>
#include <vector>

int main() {
    int n, q;
    std::cin >> n >> q;

    std::vector<std::tuple<int, int, std::string>> queries(q);
    for (auto &[op, p, s] : queries) {
        std::cin >> op;
        switch (op) {
            case 1: std::cin >> p, p--; break;
            case 2: std::cin >> p >> s, p--; break;
            case 3: std::cin >> p, p--; break;
            default: throw std::runtime_error("invalid input");
        }
    }

    const int SERVER_INDEX = n;

    auto dfs = [&](auto &&self, const int query_index, const int serach_pc_index) -> std::string {
        if (query_index == -1) return "";

        const auto &[op, p, s] = queries[query_index];
        switch (op) {
            case 1: {
                if (serach_pc_index != p) break;
                return self(self, query_index - 1, SERVER_INDEX);
            }
            case 2: {
                if (serach_pc_index != p) break;
                return self(self, query_index - 1, serach_pc_index) + s;
                break;
            }
            case 3: {
                if (serach_pc_index != SERVER_INDEX) break;
                return self(self, query_index - 1, p);
                break;
            }
            default: throw std::runtime_error("invalid option");
        }
        return self(self, query_index - 1, serach_pc_index);
    };

    std::cout << dfs(dfs, q - 1, SERVER_INDEX) << std::endl;
    return 0;
}