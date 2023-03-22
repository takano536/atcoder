#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

int main()
{
    int n;
    std::string s;
    std::cin >> n >> s;

    std::map<char, std::pair<int, int>> dist = {
        {'R', std::pair<int, int>(1, 0)},
        {'L', std::pair<int, int>(-1, 0)},
        {'U', std::pair<int, int>(0, 1)},
        {'D', std::pair<int, int>(0, -1)}
    };

    int ans = 0;
    auto curr_pos = std::pair<int, int>(0, 0);
    std::map<std::pair<int, int>, bool> is_visited = {{curr_pos, true}};
    for (const auto &c : s) {
        curr_pos.first += dist[c].first, curr_pos.second += dist[c].second;
        if (is_visited[curr_pos]) {
            ans++;
        } else {
            is_visited[curr_pos] = true;
        }
    }

    std::cout << (ans > 0 ? "Yes" : "No") << std::endl;
    return 0;
}