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
    vector<pair<double, double>> sect(n);
    rep (i, n)
    {
        int t;
        double l, r;
        cin >> t >> l >> r;
        switch (t)
        {
            case 1:
                sect[i] = make_pair(l, r);
                break;
            case 2:
                sect[i] = make_pair(l, r - 0.1);
                break;
            case 3:
                sect[i] = make_pair(l + 0.1, r);
                break;
            case 4:
                sect[i] = make_pair(l + 0.1, r - 0.1);
                break;
        }
    }

    int ans = 0;
    rep (i, n)
        for (int j = i + 1; j < n; j++)
            ans += (max(sect[i].first, sect[j].first) <= min(sect[i].second, sect[j].second));

    cout << ans << endl;
    return 0;
}