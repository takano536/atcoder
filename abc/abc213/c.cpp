#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

int main()
{
    int h, w, n;
    cin >> h >> w >> n;
    vector<int> a(n), b(n);
    rep (i, n)
        cin >> a[i] >> b[i];

    vector<int> sorted_a = a, sorted_b = b;
    sort(sorted_a.begin(), sorted_a.end());
    sort(sorted_b.begin(), sorted_b.end());
    sorted_a.erase(unique(sorted_a.begin(), sorted_a.end()), sorted_a.end());
    sorted_b.erase(unique(sorted_b.begin(), sorted_b.end()), sorted_b.end());
    rep (i, n)
    {
        int ans_a, ans_b;
        ans_a = lower_bound(sorted_a.begin(), sorted_a.end(), a[i]) - sorted_a.begin();
        ans_b = lower_bound(sorted_b.begin(), sorted_b.end(), b[i]) - sorted_b.begin();
        cout << ans_a + 1 << ' ' << ans_b + 1 << endl;
    }

    return 0;
}