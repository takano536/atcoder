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
    vector<int> a(n), b(n);
    rep (i, n)
        cin >> a[i];
    rep (i, n)
        cin >> b[i];

    vector<bool> ok(1010, true);
    rep (i, n)
    {
        for (int j = 1; j < a[i]; j++)
            ok[j] = false;
        for (int j = b[i] + 1; j <= 1000; j++)
            ok[j] = false;
    }

    int ans = 0;
    for (int i = 1; i <= 1000; i++)
        if (ok[i])
            ans++;
    cout << ans << endl;
    return 0;
}