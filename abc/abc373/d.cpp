#include <cassert>
#include <iostream>
#include <vector>

class UnionFind {
  private:
    std::vector<int> parent;
    std::vector<int> rank;
    std::vector<long long> diff_weight;

  public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        diff_weight.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x) return x;

        int root = find(parent[x]);
        diff_weight[x] += diff_weight[parent[x]];
        parent[x] = root;
        return root;
    }

    void unite(int x, int y, long long w) {
        int root_x = find(x);
        int root_y = find(y);
        if (root_x != root_y) {
            if (rank[root_x] > rank[root_y]) {
                parent[root_y] = root_x;
                diff_weight[root_y] = diff_weight[x] - diff_weight[y] + w;
            } else if (rank[root_x] < rank[root_y]) {
                parent[root_x] = root_y;
                diff_weight[root_x] = diff_weight[y] - diff_weight[x] - w;
            } else {
                parent[root_y] = root_x;
                diff_weight[root_y] = diff_weight[x] - diff_weight[y] + w;
                rank[root_x]++;
            }
        }
    }

    bool same(int x, int y) { return find(x) == find(y); }

    long long weight(int x) {
        find(x);
        return diff_weight[x];
    }
};

int main() {
    int n, m;
    std::cin >> n >> m;

    UnionFind uf(n);
    std::vector<int> u(m), v(m), w(m);
    for (int i = 0; i < m; i++) {
        std::cin >> u[i] >> v[i] >> w[i];
        u[i]--, v[i]--;
        uf.unite(u[i], v[i], w[i]);
    }

    for (int i = 0; i < n; i++) std::cout << uf.weight(i) << ' ';
    for (int i = 0; i < m; i++) assert(uf.weight(v[i]) - uf.weight(u[i]) == w[i]);
    std::cout << std::endl;

    return 0;
}