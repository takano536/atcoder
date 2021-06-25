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

    int ans = 1e9;
    rep (i, n)
    {
        int a, p, x;
        cin >> a >> p >> x;
        if (x - a > 0)
            ans = min(ans, p);
    }
    cout << (ans == 1e9 ? -1 : ans) << endl;
    return 0;
}