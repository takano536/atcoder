#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

struct Edge
{
    int a, b, c;
};

int main()
{
    int n, m;
    cin >> n >> m;
    ll ans = 0;
    dsu union_find(n);
    vector<Edge> edge(m);
    for (auto& e : edge)
        cin >> e.a >> e.b >> e.c, e.a--, e.b--, ans += e.c;

    sort(edge.begin(), edge.end(), [](const Edge& p, const Edge& q) { return p.c < q.c; });
    for (auto iter = edge.begin(); iter != edge.end(); iter++)
    {
        if (!union_find.same(iter->a, iter->b) || iter->c < 0)
        {
            union_find.merge(iter->a, iter->b);
            ans -= iter->c;
        }
    }

    cout << ans << endl;
    return 0;
}