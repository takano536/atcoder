#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

int main()
{
    int q;
    cin >> q;

    ll sum = 0;
    multiset<ll> st;
    rep (i, q)
    {
        int p, x;
        cin >> p;
        if (p == 1)
        {
            cin >> x;
            st.insert(x - sum);
        }
        if (p == 2)
        {
            cin >> x;
            sum += x;
        }
        if (p == 3)
        {
            cout << *st.begin() + sum << endl;
            st.erase(st.begin());
        }
    }
    return 0;
}