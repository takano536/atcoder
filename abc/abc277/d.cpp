#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    vector<ll> sum = a;
    bool is_continuous = true;
    int discontinuous_index = -1;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] == a[i + 1] || a[i] + 1 == a[i + 1]) {
            sum[i + 1] += sum[i];
        } else if (is_continuous) {
            is_continuous = false;
            discontinuous_index = i;
        }
    }
    if (!is_continuous && a[n - 1] == m - 1 && a[0] == 0) {
        sum[discontinuous_index] += sum[n - 1];
    }

    cout << accumulate(a.begin(), a.end(), -*max_element(sum.begin(), sum.end())) << endl;
    return 0;
}