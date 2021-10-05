#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

class cumsum
{
private:
    vector<int> v;
    int n;

public:
    cumsum(vector<int> &v)
    {
        n = v.size();
        this->v.resize(n + 1);
        for (int i = 0; i < n; i++)
            this->v[i + 1] = this->v[i] + v[i];
    }

    // sum of [left, right)
    int sum(int left, int right)
    {
        if (left < 0 || right > n)
            return -1e9;
        return this->v[right] - this->v[left];
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> one(n), two(n);
    rep (i, n)
    {
        int c;
        cin >> c;
        c == 1 ? cin >> one[i] : cin >> two[i];
    }

    cumsum one_sum(one), two_sum(two);

    int q;
    cin >> q;
    rep (i, q)
    {
        int l, r;
        cin >> l >> r;
        l--;
        cout << one_sum.sum(l, r) << ' ' << two_sum.sum(l, r) << endl;
    }
    return 0;
}