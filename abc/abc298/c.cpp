#include <algorithm>
#include <iostream>
#include <map>
#include <set>

int main() {
    int n, q;
    std::cin >> n >> q;

    std::map<int, std::map<int, int>> boxes;
    std::map<int, std::set<int>> box_ids;
    for (int i = 0; i < q; i++) {
        int query;
        std::cin >> query;

        switch (query) {
            case 1: {
                int a, b;
                std::cin >> a >> b;

                boxes[b][a]++;
                box_ids[a].insert(b);
                break;
            }
            case 2: {
                int a;
                std::cin >> a;

                for (const auto &[card, cnt] : boxes[a]) {
                    for (int j = 0; j < cnt; j++) {
                        std::cout << card << ' ';
                    }
                }
                std::cout << std::endl;
                break;
            }
            case 3: {
                int a;
                std::cin >> a;

                for (const auto &id : box_ids[a]) {
                    std::cout << id << ' ';
                }
                std::cout << std::endl;
                break;
            }
        }
    }
    return 0;
}