#include <algorithm>
#include <array>
#include <chrono>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <vector>

#include <atcoder/dsu>

const int MAX_POWER = 5000;
const int MIN_POWER = 0;
const int MAX_EDGE = 300;
const int MAX_VERTEX = 100;

//_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

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

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        std::cin >> x[i] >> y[i];
    }

    std::array<std::array<int, MAX_VERTEX>, MAX_VERTEX> edge_ids;
    std::array<std::array<int, MAX_VERTEX>, MAX_VERTEX> edge_costs;
    const int NaN = -1;
    for (auto &v : edge_ids) {
        v.fill(NaN);
    }
    for (auto &v : edge_costs) {
        v.fill(NaN);
    }

    std::vector<int> u(m), v(m), w(m);
    std::vector<std::vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
        std::cin >> u[i] >> v[i] >> w[i];
        u[i]--, v[i]--;

        edge_ids[u[i]][v[i]] = i, edge_ids[v[i]][u[i]] = i;
        edge_costs[u[i]][v[i]] = w[i], edge_costs[v[i]][u[i]] = w[i];

        graph[u[i]].push_back(v[i]);
        graph[v[i]].push_back(u[i]);
    }

    std::vector<int> a(k), b(k);
    for (int i = 0; i < k; i++) {
        std::cin >> a[i] >> b[i];
    }

    // 不要な辺を消す
    std::vector<int> is_active(m, false);

    std::array<long long, MAX_VERTEX> min_costs;
    const long long INF = 1e18;
    min_costs.fill(INF);

    struct Edge {
        long long cost;
        int from, prev;
        Edge(long long cost, int from, int prev) : cost(cost), from(from), prev(prev) {
        }
        bool operator>(const Edge &other) const {
            return cost > other.cost;
        }
    };

    std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> heap;
    heap.emplace(0, 0, -1);

    while (!heap.empty()) {
        auto [cost, from, prev] = heap.top();
        heap.pop();

        if (min_costs[from] != INF) {
            continue;
        }

        if (prev != -1) {
            is_active[edge_ids[from][prev]] = true;
        }
        min_costs[from] = cost;

        for (const auto &to : graph[from]) {
            if (cost + edge_costs[from][to] >= min_costs[to]) {
                continue;
            }
            heap.emplace(cost + edge_costs[from][to], to, from);
        }
    }

    std::vector<int> power(n, MAX_POWER);

    atcoder::dsu union_find(n);
    for (int i = 0; i < m; i++) {
        if (!is_active[i]) {
            continue;
        }
        union_find.merge(u[i], v[i]);
    }

    for (int i = 0; i < n; i++) {
        power[i] = get_rand() % MAX_POWER;
    }

    for (int i = 0; i < n; i++) {
        std::cout << power[i] << ' ';
    }
    std::cout << std::endl;
    for (int i = 0; i < m; i++) {
        std::cout << (is_active[i] ? 1 : 0) << ' ';
    }
    std::cout << std::endl;
    return 0;
}