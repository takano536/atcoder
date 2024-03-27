#include <iostream>
#include <numeric>
#include <set>
#include <vector>

int main() {
    int n, q;
    std::cin >> n >> q;

    std::vector<int> head_ids(n), tail_ids(n);
    for (int i = 0; i < n; i++) {
        head_ids[i] = i;
        tail_ids[i] = i;
    }

    for (int query = 0; query < q; query++) {
        int opt;
        std::cin >> opt;

        switch (opt) {
            case 1: {
                int x, y;
                std::cin >> x >> y;
                x--, y--;

                tail_ids[x] = y;
                head_ids[y] = x;

                break;
            }
            case 2: {
                int x, y;
                std::cin >> x >> y;
                x--, y--;

                tail_ids[x] = x;
                head_ids[y] = y;

                break;
            }
            case 3: {
                int x;
                std::cin >> x;
                x--;

                int curr = x;
                std::vector<int> train;
                while (head_ids[curr] != curr) {
                    curr = head_ids[curr];
                }
                while (tail_ids[curr] != curr) {
                    train.push_back(curr);
                    curr = tail_ids[curr];
                }
                train.push_back(curr);

                std::cout << train.size() << ' ';
                for (const auto &id : train) {
                    std::cout << id + 1 << ' ';
                }
                std::cout << std::endl;

                break;
            }
            default: {
                exit(1);
            }
        }
    }
    return 0;
}