#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    rep (i, n)
        cin >> a[i];

    vector<ll> cnt(n);
    rep (i, n)
        cnt[i] = a[i] - (i + 1);

    rep (i, q)
    {
        ll k;
        cin >> k;
        ll ans = lower_bound(cnt.begin(), cnt.end(), k) - cnt.begin() + k;
        cout << ans << endl;
    }
    return 0;
}