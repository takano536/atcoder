#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> p(n);
    unordered_map<int, unordered_map<int, int>> exists;
    rep (i, n)
        cin >> p[i].first >> p[i].second, exists[p[i].first][p[i].second] = 1;

    sort(p.begin(), p.end());

    ll ans = 0;
    rep (i, n)
    {
        rep (j, n)
        {
            if (i == j)
                continue;

            int vector_x = p[j].first - p[i].first;
            int vector_y = p[j].second - p[i].second;
            bool x_equals = (vector_x == 0 ? true : false);
            bool y_equals = (vector_y == 0 ? true : false);
            if (!x_equals and !y_equals)
                continue;

            rep (k, n)
            {
                if (j == k || k == i)
                    continue;

                if (x_equals && p[k].first - p[j].first == 0)
                    continue;
                if (y_equals && p[k].second - p[j].second == 0)
                    continue;
                if (p[k].first - p[j].first != 0 && p[k].second - p[j].second != 0)
                    continue;

                int next_x = p[k].first - vector_x;
                int next_y = p[k].second - vector_y;
                if (exists[next_x][next_y])
                    ans++;
            }
        }
    }

    cout << ans / 8 << endl;
    return 0;
}