#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

int main()
{
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    rep (i, h)
        rep (j, w)
            cin >> a[i][j];

    vector<int> hori_sum(h, 0), vert_sum(w, 0);
    rep (i, h)
        hori_sum[i] = accumulate(a[i].begin(), a[i].end(), 0);
    rep (i, w)
        rep (j, h)
            vert_sum[i] += a[j][i];

    rep (i, h)
    {
        rep (j, w)
            cout << hori_sum[i] + vert_sum[j] - a[i][j] << ' ';
        cout << endl;
    }
    return 0;
}