#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

vector<int> prime(int n)
{
    vector<int> ret;
    for (int a = 2; a * a <= n; ++a)
    {
        if (n % a != 0)
            continue;
        int cnt = 0;
        while (n % a == 0)
        {
            cnt++;
            n /= a;
        }
        ret.push_back(a);
    }
    if (n != 1)
        ret.push_back(n);
    return ret;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<bool> ok(m + 1, true);
    set<int> seen;
    rep (i, n)
    {
        int a;
        cin >> a;
        vector<int> primes = prime(a);
        for (const auto& i : primes)
            if (seen.insert(i).second)
            {
                for (int j = i; j <= m; j += i)
                    if (ok[j])
                        ok[j] = false;
            }
    }

    vector<int> ans;
    for (int i = 1; i <= m; i++)
        if (ok[i])
            ans.push_back(i);
    cout << ans.size() << endl;
    for (const auto& i : ans)
        cout << i << endl;
    return 0;
}