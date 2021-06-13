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
    vector<int> a(n), b(n), c(n);
    rep (i, n)
        cin >> a[i];
    rep (i, n)
        cin >> b[i];
    rep (i, n)
        cin >> c[i], c[i]--;

    ll ans = 0;
    vector<int> cnt(n + 1);
    rep (i, n)
        cnt[b[c[i]]]++;
    rep (i, n)
        ans += cnt[a[i]];

    cout << ans << endl;
    return 0;
}