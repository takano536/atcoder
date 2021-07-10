#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

int main()
{
    vector<int> m(10, 1);
    for (int i = 1; i <= 10; i++)
        rep (j, i)
            m[i - 1] *= (j + 1);

    int p;
    cin >> p;

    int ans = 0;
    rep (i, 10)
    {
        ans += floor(p / m[9 - i]);
        p -= floor(p / m[9 - i]) * m[9 - i];
    }

    cout << ans << endl;
    return 0;
}