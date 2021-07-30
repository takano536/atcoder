#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

pair<int, int> bfs(const vector<vector<int>> &graph, int sv)
{
    int n = graph.size();
    vector<int> dist(n, -1);
    queue<int> que;
    int gv = sv;
    dist[sv] = 0;
    que.push(sv);
    while (!que.empty())
    {
        int v = que.front();
        que.pop();
        for (auto nv : graph[v])
        {
            if (dist[nv] != -1)
                continue;
            dist[nv] = dist[v] + 1;
            gv = nv;
            que.push(nv);
        }
    }
    return make_pair(gv, *max_element(dist.begin(), dist.end()));
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    rep (i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    // 木の直径は 2 回最短経路計算
    cout << bfs(g, bfs(g, 0).first).second + 1 << endl;
    return 0;
}