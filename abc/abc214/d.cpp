#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

struct Edge
{
    int u, v;
    int w;
};

int main()
{
    int n;
    cin >> n;
    vector<Edge> edge(n - 1);
    rep (i, n - 1)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        edge[i] = Edge{u, v, w};
    }

    sort(edge.begin(), edge.end(), [](const Edge& p, const Edge& q){return p.w < q.w;});
    ll ans = 0;
    dsu d(n);
    for (const auto& e : edge)
    {
        ans += ll(e.w) * d.size(e.u) * d.size(e.v);
        d.merge(e.u, e.v);
    }

    cout << ans << endl;
    return 0;
}