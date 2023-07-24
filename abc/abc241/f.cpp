#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

namespace my_modules {

class CoordCompressor {
  public:
    CoordCompressor() {
    }
    void add(int first, int second) {
        coords.emplace_back(first, second);
    }
    void add(const std::pair<int, int> &p) {
        coords.push_back(p);
    }
    void sort() {
        std::sort(coords.begin(), coords.end());
        coords.erase(std::unique(coords.begin(), coords.end()), coords.end());
    }
    std::pair<int, int> operator[](int i) const {
        return coords[i];
    }
    int operator()(int first, int second) const {
        return std::lower_bound(coords.begin(), coords.end(), std::make_pair(first, second)) - coords.begin();
    }
    int operator()(const std::pair<int, int> &p) const {
        return std::lower_bound(coords.begin(), coords.end(), p) - coords.begin();
    }
    int size() const {
        return coords.size();
    }

  private:
    std::vector<std::pair<int, int>> coords;
};

}  // namespace my_modules

int main() {
    const int INF = -1;
    const std::vector<std::pair<int, int>> DIRECTIONS = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    my_modules::CoordCompressor coord_compressor;

    int h, w, n;
    std::cin >> h >> w >> n;

    std::pair<int, int> s, g;
    std::cin >> s.first >> s.second;
    std::cin >> g.first >> g.second;
    s.first--, s.second--;
    g.first--, g.second--;

    coord_compressor.add(s);
    coord_compressor.add(g);

    std::vector<std::pair<int, int>> stones(n);
    std::map<int, std::set<int>> vertical_stones, horizontal_stones;
    for (auto &stone : stones) {
        std::cin >> stone.first >> stone.second;
        stone.first--, stone.second--;

        vertical_stones[stone.second].insert(stone.first);
        horizontal_stones[stone.first].insert(stone.second);

        for (auto &direction : DIRECTIONS) {
            int first = stone.first + direction.first;
            int second = stone.second + direction.second;
            if (first < 0 || first >= h || second < 0 || second >= w) {
                continue;
            }
            coord_compressor.add(first, second);
        }
    }

    coord_compressor.sort();

    std::queue<std::pair<int, int>> que;
    que.push(s);
    std::vector<int> dist(coord_compressor.size(), INF);
    dist[coord_compressor(s)] = 0;

    while (!que.empty()) {
        const auto curr = que.front();
        que.pop();
        const int curr_dist = dist[coord_compressor(curr)];

        auto next_vert_iter = vertical_stones[curr.second].lower_bound(curr.first);
        if (next_vert_iter != vertical_stones[curr.second].end()) {
            // bottom
            int next_first = *next_vert_iter - 1;
            if (dist[coord_compressor(next_first, curr.second)] == INF) {
                dist[coord_compressor(next_first, curr.second)] = curr_dist + 1;
                que.push({next_first, curr.second});
            }
        }
        if (next_vert_iter != vertical_stones[curr.second].begin()) {
            // top
            int next_first = *std::prev(next_vert_iter) + 1;
            if (dist[coord_compressor(next_first, curr.second)] == INF) {
                dist[coord_compressor(next_first, curr.second)] = curr_dist + 1;
                que.push({next_first, curr.second});
            }
        }

        auto next_horiz_iter = horizontal_stones[curr.first].lower_bound(curr.second);
        if (next_horiz_iter != horizontal_stones[curr.first].end()) {
            // right
            int next_second = *next_horiz_iter - 1;
            if (dist[coord_compressor(curr.first, next_second)] == INF) {
                dist[coord_compressor(curr.first, next_second)] = curr_dist + 1;
                que.push({curr.first, next_second});
            }
        }
        if (next_horiz_iter != horizontal_stones[curr.first].begin()) {
            // left
            int next_second = *std::prev(next_horiz_iter) + 1;
            if (dist[coord_compressor(curr.first, next_second)] == INF) {
                dist[coord_compressor(curr.first, next_second)] = curr_dist + 1;
                que.push({curr.first, next_second});
            }
        }
    }

    std::cout << dist[coord_compressor(g)] << std::endl;
    return 0;
}