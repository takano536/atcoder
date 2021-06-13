#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

int bfs(const vector<vector<int>> &graph, int sv)
{
    int n = graph.size();
    vector<int> dist(n, -1);
    int ret = 1;
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
            ret++;
            que.push(nv);
        }
    }
    return ret;
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
    }

    int ans = 0;
    rep (i, n)
        ans += bfs(g, i);
    cout << ans << endl;
    return 0;
}