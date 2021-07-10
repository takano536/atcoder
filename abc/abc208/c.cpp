#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

struct A
{
    int index;
    ll num;
    ll ans;
};

bool cmp_index(A a, A b)
{
    return a.index < b.index;
}

bool cmp_num(A a, A b)
{
    return a.num < b.num;
}

int main()
{
    ll n, k;
    cin >> n >> k;
    vector<A> a(n);
    rep (i, n)
    {
        ll num;
        cin >> num;
        a[i] = A{i, num, 0};
    }

    sort(a.begin(), a.end(), cmp_num);
    ll mod = k % n;
    long double div = (long double)k / n;
    ll cnt = floor(div);
    rep (i, n)
        a[i].ans = i < mod ? cnt + 1 : cnt;

    sort(a.begin(), a.end(), cmp_index);
    rep (i, n)
        cout << a[i].ans << endl;
    return 0;
}