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
    vector<int> a(n), b(n);
    rep (i, n)
        cin >> a[i];
    rep (i, n)
        cin >> b[i];

    int diff = 0;
    rep (i, n)
        diff += abs(a[i] - b[i]);

    cout << (k >= diff && k % 2 == diff % 2 ? "Yes" : "No") << endl;
    return 0;
}