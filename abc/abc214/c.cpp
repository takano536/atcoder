#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

struct cumsum
{
    vector<long long> v;
    int n;

    cumsum(vector<long long> &v)
    {
        n = v.size();
        this->v.resize(n + 1);
        for (int i = 0; i < n; i++)
            this->v[i + 1] = this->v[i] + v[i];
    }

    // sum of [left, right)
    long long sum(int left, int right)
    {
        if (left < 0 || right > n)
            return 1e18;
        return this->v[right] - this->v[left];
    }
};

int main()
{
    int n;
    cin >> n;
    vector<ll> s(n + n), t(n);
    rep (i, n)
        cin >> s[i];
    rep (i, n)
        cin >> t[i];

    for (int i = n; i < n + n; i++)
        s[i] = s[i % n];
    cumsum s_sum(s);

    int start_index = 0;
    vector<ll> ans(n, 1e18);
    rep (i, n + n)
    {
        if (i == 0)
        {
            ans[i] = t[0];
            continue;
        }

        if (t[i % n] <= s_sum.sum(start_index, i) + t[start_index % n])
            start_index = i;
        ans[i % n] = min(ans[i % n], min(s_sum.sum(start_index, i) + t[start_index % n], t[i % n]));
    }

    rep (i, n)
        cout << ans[i] << endl;
    return 0;
}