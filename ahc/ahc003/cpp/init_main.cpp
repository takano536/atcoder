#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

const int MAX_QUERY = 1000;

int main()
{
    rep (i, MAX_QUERY)
    {
        int si, sj, ti, tj;
        cin >> si >> sj >> ti >> tj;

        string ans = "";
        while (si != ti)
        {
            ans += si > ti ? 'U' : 'D';
            si += si > ti ? -1 : 1;
        }
        while (sj != tj)
        {
            ans += sj > tj ? 'L' : 'R';
            sj += sj > tj ? -1 : 1;
        }

        cout << ans << endl << flush;

        int temp;
        cin >> temp;
    }
    return 0;
}