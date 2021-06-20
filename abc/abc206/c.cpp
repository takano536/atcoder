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
    vector<int> a(n);
    unordered_map<int, int> cnt;
    rep (i, n)
        cin >> a[i];
    rep (i, n)
        cnt[a[i]]++;
    
    ll ans = 0;
    rep (i, n)
    {
        ans += (n - i) - cnt[a[i]];
        cnt[a[i]]--;
    }

    cout << ans << endl;
    return 0;
}