#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

int main()
{
    string n;
    cin >> n;

    int len = n.size();
    sort(n.begin(), n.end());
    ll ans = 0;
    do
    {
        rep (i, len - 1)
        {
            string a_str = n.substr(0, i + 1);
            string b_str = n.substr(i + 1, len - (i + 1));
            if (a_str[0] == '0' || b_str[0] == '0')
                continue;
            ll a = atoi(a_str.c_str());
            ll b = atoi(b_str.c_str());
            ans = max(a * b, ans);
        }
    } while (next_permutation(n.begin(), n.end()));

    cout << ans << endl;
    return 0;
}