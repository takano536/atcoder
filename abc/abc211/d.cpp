#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

using mint = modint1000000007;

int bfs(const vector<vector<int>> &graph, int sv)
{
    int n = graph.size();
    vector<int> dist(n, -1);
    vector<mint> cnt(n, 0);
    queue<int> que;
    dist[sv] = 0;
    cnt[sv] = 1;
    que.push(sv);
    while (!que.empty())
    {
        int v = que.front();
        que.pop();
        for (auto nv : graph[v])
        {
            if (dist[nv] == -1)
            {
                dist[nv] = dist[v] + 1;
                cnt[nv] = cnt[v];
                que.push(nv);
            }
            else if (dist[nv] == dist[v] + 1)
            {
                cnt[nv] += cnt[v];
                continue;
            }
            else
                continue;
        }
    }
    return cnt[n - 1].val();
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    rep (i, m)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    cout << bfs(g, 0) << endl;
    return 0;
}