#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    vector<int> b(n);
    unordered_map<ll, ll> v;
    set<ll> st;
    rep (i, n)
        cin >> a[i] >> b[i], v[a[i]] += b[i], st.insert(a[i]);

    ll ans = 0;
    ll money = k;
    ll now = 0;
    for (ll index : st)
    {
        money -= (index - now);
        ans += (index - now);
        if (money < 0)
        {
            ans += money;
            break;
        }
        money += v[index];
        now = ans;
    }
    if (money > 0)
        ans += money;
    cout << ans << endl;
    return 0;
}