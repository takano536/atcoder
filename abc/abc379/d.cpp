#include <iostream>
#include <queue>
#include <stdexcept>
#include <utility>
#include <vector>

int main() {
    int q;
    std::cin >> q;

    std::vector<long long> growth_cumsum{0};
    std::queue<std::pair<int, int>> plant_queries;
    int i = 0;
    while (q--) {
        int opt;
        std::cin >> opt;

        switch (opt) {
            case 1: {
                if (plant_queries.empty()) {
                    plant_queries.emplace(1, i);
                    break;
                }

                auto &[num, time] = plant_queries.back();
                if (time == i) {
                    num++;
                    break;
                }

                plant_queries.emplace(1, i);
                break;
            }

            case 2: {
                int t;
                std::cin >> t;
                growth_cumsum.push_back(growth_cumsum.back() + t);
                i++;
                break;
            }

            case 3: {
                int h;
                std::cin >> h;

                long long ans = 0;
                while (!plant_queries.empty()) {
                    const auto &[num, time] = plant_queries.front();

                    const auto height = growth_cumsum[i] - growth_cumsum[time];
                    if (height < h) break;

                    ans += num;
                    plant_queries.pop();
                }

                std::cout << ans << std::endl;
                break;
            }

            default:
                throw std::runtime_error("invalid queries");
                return -1;
        }
    }
    return 0;
}