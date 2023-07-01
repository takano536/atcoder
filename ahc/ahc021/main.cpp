#include <algorithm>
#include <chrono>
#include <iostream>
#include <numeric>
#include <random>
#include <set>
#include <vector>

const int MAX_STEPS = 30;
const int MAX_BALLS = MAX_STEPS * (MAX_STEPS + 1) / 2;
const int MAX_SWAP_CNT = 10000;
const int SWAP_DIRECTION_CNT = 6;
const int TIME_LIMIT = 1800;

//_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

namespace mymodules {

class Timer {
  public:
    Timer() {
        start = std::chrono::system_clock::now();
    }
    int64_t get_elapsed() {
        const auto end = std::chrono::system_clock::now();
        return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    }

  private:
    std::chrono::system_clock::time_point start;
};

//_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

std::random_device rd;
static std::mt19937_64 mt64(rd());
uint64_t get_rand() {
    return mt64();
}

//_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

struct Coord {
    int x;
    int y;
    Coord(int x, int y) : x(x), y(y) {
    }
    Coord() {
        x = 0, y = 0;
    }

    bool operator==(const Coord &rhs) const {
        return x == rhs.x && y == rhs.y;
    }
    bool operator!=(const Coord &rhs) const {
        return !(*this == rhs);
    }
};

//_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

class Pyramid {
  public:
    Pyramid() {
        best_swap_cnt = MAX_SWAP_CNT;
    }

    void initialize(std::array<std::array<int, MAX_STEPS>, MAX_STEPS> &b) {
        for (int i = 0; i < MAX_STEPS; i++) {
            if (!empty_spaces[i].empty()) {
                empty_spaces[i].clear();
            }
        }
        for (int i = 0; i < MAX_STEPS; i++) {
            for (int j = 0; j <= i; j++) {
                pyramid[i][j] = b[i][j];
                coords[pyramid[i][j]] = Coord(i, j);
                empty_spaces[i].insert(j);
            }
        }
        swap_cnt = 0;
    }

    Coord find(int num) {
        return coords[num];
    }

    void move(const Coord &start, const Coord &end) {
        auto prev = start;
        auto next = start;
        while (next != end && swap_cnt < MAX_SWAP_CNT) {
            next.x += next.x == end.x ? 0 : (end.x - next.x) / std::abs(end.x - next.x);
            next.y += next.y == end.y ? 0 : (end.y - next.y) / std::abs(end.y - next.y);

            if (empty_spaces[next.x].find(next.y) == empty_spaces[next.x].end() && prev.x - next.x > 0) {
                next.x -= (end.x - prev.x) / std::abs(end.x - prev.x);
            }

            if (prev.x - next.x != 0 && prev.y - next.y != 0 && prev.x - next.x != prev.y - next.y) {
                next.x -= (end.x - prev.x) / std::abs(end.x - prev.x);
            }

            if (prev == next) {
                output_history();
                exit(1);
            }

            swap_history[swap_cnt++] = {prev, next};
            std::swap(coords[pyramid[prev.x][prev.y]], coords[pyramid[next.x][next.y]]);
            std::swap(pyramid[prev.x][prev.y], pyramid[next.x][next.y]);
            prev = next;
        }
        empty_spaces[end.x].erase(end.y);

        if (swap_cnt >= MAX_SWAP_CNT) {
            output_history();
            exit(1);
        }
    }

    void move(const Coord &start, const int step) {
        move(start, find_empty_space(step, start.y));
    }

    Coord find_empty_space(int step, int y) {
        int dist = 1e9;
        Coord res;
        for (auto space : empty_spaces[step]) {
            if (std::abs(space - y) < dist) {
                dist = std::abs(space - y);
                res = {step, space};
            }
        }
        return res;
    }

    void update() {
        if (swap_cnt >= best_swap_cnt) {
            return;
        }

        best_swap_cnt = swap_cnt;
        for (int i = 0; i < swap_cnt; i++) {
            best_swap_history[i] = swap_history[i];
        }
    }

    void output_history() {
        std::cout << best_swap_cnt << std::endl;
        for (int i = 0; i < best_swap_cnt; i++) {
            std::cout << best_swap_history[i].first.x << " " << best_swap_history[i].first.y << " "
                      << best_swap_history[i].second.x << " " << best_swap_history[i].second.y << std::endl;
        }
    }

  private:
    std::array<std::array<int, MAX_STEPS>, MAX_STEPS> pyramid;
    std::array<Coord, MAX_BALLS> coords;
    std::array<std::set<int>, MAX_STEPS> empty_spaces;

    int swap_cnt;
    std::array<std::pair<Coord, Coord>, MAX_SWAP_CNT> swap_history;

    int best_swap_cnt;
    std::array<std::pair<Coord, Coord>, MAX_SWAP_CNT> best_swap_history;
};

}    // namespace mymodules

//_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

int main() {
    mymodules::Timer timer;

    std::array<std::array<int, MAX_STEPS>, MAX_STEPS> b;
    for (int i = 0; i < MAX_STEPS; i++) {
        for (int j = 0; j <= i; j++) {
            std::cin >> b[i][j];
        }
    }

    mymodules::Pyramid pyramid;

    while (timer.get_elapsed() < TIME_LIMIT) {
        pyramid.initialize(b);

        for (int step = 0; step < MAX_STEPS - 1; step++) {
            std::vector<int> ball_ids(step + 1);
            std::iota(ball_ids.begin(), ball_ids.end(), step * (step + 1) / 2);
            std::shuffle(ball_ids.begin(), ball_ids.end(), std::mt19937_64(mymodules::mt64));

            for (auto id : ball_ids) {
                pyramid.move(pyramid.find(id), step);
            }
        }

        pyramid.update();
    }

    pyramid.output_history();
    return 0;
}