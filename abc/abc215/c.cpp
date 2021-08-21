#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

int main()
{
    string s;
    int k;
    cin >> s >> k;
    sort(s.begin(), s.end());

    int cnt = 1;
    do
    {
        if (cnt == k)
        {
            cout << s << endl;
            return 0;
        }
        cnt++;
    } while (next_permutation(s.begin(), s.end()));

    return 0;
}