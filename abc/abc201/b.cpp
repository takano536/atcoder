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
    vector<pair<int, string>> m(n);
    rep (i, n)
        cin >> m[i].second >> m[i].first;

    sort(m.rbegin(), m.rend());

    cout << m[1].second << endl;
    return 0;
}