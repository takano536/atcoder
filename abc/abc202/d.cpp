#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

int main()
{
    int a, b;
    ll k;
    cin >> a >> b >> k;

    int size = 60;
    vector<vector<ll>> nCr(size + 1, vector<ll>(size + 1));
    nCr[0][0] = 1;
    rep (i, size)
        rep (j, i + 1)
            nCr[i + 1][j] += nCr[i][j], nCr[i + 1][j + 1] += nCr[i][j];
    
    string ans;
    while (a + b > 0)
    {
        if (a == 0)
            ans += 'b', b--;
        else if (b == 0)
            ans += 'a', a--;
        else if (k > nCr[a - 1 + b][b])
            ans += 'b', k -= nCr[a - 1 + b][b], b--;
        else
            ans += 'a', a--;
    }

    cout << ans << endl;
    return 0;
}