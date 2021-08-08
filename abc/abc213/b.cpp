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
    vector<pair<int, int>> a(n);
    rep (i, n)
        cin >> a[i].first, a[i].second = i + 1;

    sort(a.rbegin(), a.rend());

    cout << a[1].second << endl;
    return 0;
}