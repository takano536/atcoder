#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

using mint = modint998244353;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<char> c(k);
    vector<int> o(k);
    rep (i, k)
        cin >> c[i] >> o[i];

    vector<int> cards(n, k);
    rep (i, k)
        if (c[i] == 'L')
        {
            cards[o[i] - 1] = 1;
            for (int j = o[i] - 2; j >= 0; j--)
            {
                if (cards[j] == 1)
                    continue;
                cards[j]--;
            }
        }
        else
        {
            cards[o[i] - 1] = 1;
            for (int j = o[i]; j < n; j++)
            {
                if (cards[j] == 1)
                    continue;
                cards[j]--;
            }
        }

    mint ans = 1;
    rep (i, n)
    {
        if (cards[i] < 1)
            continue;
        ans *= cards[i];
    }

    cout << ans.val() << endl;
    return 0;
}