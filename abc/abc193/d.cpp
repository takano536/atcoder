#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

bool ok(string s, string t)
{
    vector<int> takahashi_cnt(10, 0), aoki_cnt(10, 0);
    int takahashi_score = 0, aoki_score = 0;

    rep (i, 5)
        takahashi_cnt[s[i] - '0']++, aoki_cnt[t[i] - '0']++;
    
    for (int i = 1; i <= 9; i++)
        takahashi_score += i * pow(10, takahashi_cnt[i]), aoki_score += i * pow(10, aoki_cnt[i]);
    
    return takahashi_score > aoki_score;
}

int main()
{
    ll k;
    string s, t;
    cin >> k >> s >> t;

    vector<ll> cnt(10, k);
    rep (i, 4)
        cnt[s[i] - '0']--, cnt[t[i] - '0']--;

    ll win_cnt = 0;
    for (int i = 1; i <= 9; i++)
        for (int j = 1; j <= 9; j++)
        {
            s.pop_back(), t.pop_back();
            s += to_string(i), t += to_string(j);
            if (!ok(s, t))
                continue;
            win_cnt += (i == j ? cnt[i] * (cnt[j] - 1) : cnt[i] * cnt[j]);
        }

    ll rem = 9 * k - 8;
    cout << double(win_cnt) / rem / (rem - 1) << endl;
    return 0;
}