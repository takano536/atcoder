#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

vector<int> a;
int n, l, k;

bool is_ok(long long mid)
{
    int right_end = 0;
    int cnt = 0;
    rep (i, n)
    {
        if (a[i] - right_end >= mid && l - a[i] >= mid)
        {
            cnt++;
            right_end = a[i];
        }
    }
    return cnt < k;
}

ll binary_search()
{
    ll ng = 0;
    ll ok = l;

    while (abs(ok - ng) > 1)
    {
        ll mid = (ok + ng) / 2;
        if (is_ok(mid))
            ok = mid;
        else
            ng = mid;
    }
    return ok;
}

int main()
{
    cin >> n >> l >> k;
    a.resize(n);
    rep (i, n)
        cin >> a[i];

    cout << binary_search() - 1 << endl;
    return 0;
}