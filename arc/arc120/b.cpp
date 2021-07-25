#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

using mint = modint998244353;

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> field(h);
    rep (i, h)
        cin >> field[i];

    mint ans = 1;
    rep (i, h)
    {
        int x = 0, y = i;
        vector<int> cnt(3, 0);
        while (0 <= y && y < h && 0 <= x && x < w)
        {
            switch (field[y][x])
            {
                case 'R':
                    cnt[0]++;
                    break;
                case 'B':
                    cnt[1]++;
                    break;
                case '.':
                    cnt[2]++;
                    break;
            }
            x++, y--;
        }
        if (cnt[0] == 0 && cnt[1] == 0)
            ans *= 2;
        else if (cnt[0] > 0 && cnt[1] > 0)
            ans = 0;
    }
    for (int i = 1; i < w; i++)
    {
        int x = i, y = h - 1;
        vector<int> cnt(3, 0);
        while (0 <= y && y < h && 0 <= x && x < w)
        {
            switch (field[y][x])
            {
                case 'R':
                    cnt[0]++;
                    break;
                case 'B':
                    cnt[1]++;
                    break;
                case '.':
                    cnt[2]++;
                    break;
            }
            x++, y--;
        }
        if (cnt[0] == 0 && cnt[1] == 0)
            ans *= 2;
        else if (cnt[0] > 0 && cnt[1] > 0)
            ans = 0;
    }

    cout << ans.val() << endl;
    return 0;
}