#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

vector<int> bfs(const vector<vector<int>> &graph, int sv)
{
    int n = graph.size();
    vector<int> dist(n, -1);
    queue<int> que;
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
            que.push(nv);
        }
    }
    return dist;
}

int main()
{
    int n, q;
    cin >> n >> q;
    vector<vector<int>> g(n);
    rep (i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> dist = bfs(g, 0);

    rep (i, q)
    {
        int c, d;
        cin >> c >> d;
        c--, d--;
        cout << (abs(dist[c] - dist[d]) % 2 ? "Road" : "Town") << endl;
    }
    return 0;
}