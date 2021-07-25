#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

template <typename T>
struct SparseTable
{
    vector<vector<T>> st;
    vector<int> lookup;

    SparseTable(const vector<T> &v)
    {
        int b = 0;
        while ((1 << b) <= v.size())
            ++b;
        st.assign(b, vector<T>(1 << b));
        for (int i = 0; i < v.size(); i++)
            st[0][i] = v[i];
        for (int i = 1; i < b; i++)
            for (int j = 0; j + (1 << i) <= (1 << b); j++)
                st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
        lookup.resize(v.size() + 1);
        for (int i = 2; i < lookup.size(); i++)
            lookup[i] = lookup[i >> 1] + 1;
    }

    // max of [left, right)
    inline T rmq(int l, int r)
    {
        int b = lookup[r - l];
        return max(st[b][l], st[b][r - (1 << b)]);
    }
};

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
            return -1e18;
        return this->v[right] - this->v[left];
    }
};

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    rep (i, n)
        cin >> a[i];

    SparseTable<ll> a_max(a);
    vector<ll> a_sum(n + 1, 0);
    rep (i, n)
        a_sum[i + 1] = a_sum[i] + a[i];
    cumsum a_cumsum(a_sum);
    rep (i, n)
    {
        ll sum = a_max.rmq(0, i + 1) * (i + 1);
        sum += a_cumsum.sum(1, i + 2);
        cout << sum << endl;
    }

    return 0;
}