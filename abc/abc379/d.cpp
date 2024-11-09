#include <iostream>
#include <utility>
#include <vector>

#include <atcoder/fenwicktree>

int main() {
    int q;
    std::cin >> q;

    int time = 0;
    atcoder::fenwick_tree<long long> heights(q);
    std::vector<long long> cnts(q);
    int head = 0;
    while (q--) {
        int opt;
        std::cin >> opt;

        switch (opt) {
            case 1: {
                cnts[time]++;
                break;
            }
            case 2: {
                int t;
                std::cin >> t;
                heights.add(time, t);
                time++;
                break;
            }
            case 3: {
                int h;
                std::cin >> h;

                long long ans = 0;
                int next_head = head;
                for (int i = head; i <= time; i++) {
                    if (cnts[i] == 0) continue;
                    if (heights.sum(i, time + 1) >= h) {
                        ans += cnts[i];
                        cnts[i] = 0;
                        next_head = i + 1;
                    }
                }
                head = next_head;
                std::cout << ans << std::endl;
                break;
            }
            default:
                break;
        }
    }
    return 0;
}