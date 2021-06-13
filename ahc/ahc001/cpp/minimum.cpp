#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

filesystem::path p = filesystem::current_path();

int n;
vector<int> x, y, r;
vector<int> a, b, c, d;

int generate_input_file()
{
    ofstream ofs(p.parent_path().string<char>() + "/tools/src/bin/out/input.txt");
    if (!ofs)
        return -1;
    ofs << n << endl;
    rep (i, n)
        ofs << x[i] << ' ' << y[i] << ' ' << r[i] << endl;
    return 0;
}

int generate_output_file()
{
    ofstream ofs(p.parent_path().string<char>() + "/tools/src/bin/out/output.txt");
    if (!ofs)
        return -1;
    rep (i, n)
        ofs << a[i] << ' ' << b[i] << ' ' << c[i] << ' ' << d[i] << endl;
    return 0;
}

int main()
{
    cin >> n;
    x.resize(n), y.resize(n), r.resize(n);
    a.resize(n), b.resize(n), c.resize(n), d.resize(n);
    rep (i, n)
        cin >> x[i] >> y[i] >> r[i];

    rep (i, n)
    {
        a[i] = x[i];
        b[i] = y[i];
        c[i] = x[i] + 1;
        d[i] = y[i] + 1;
    }

    rep (i, n)
        printf("%d %d %d %d\n", a[i], b[i], c[i], d[i]);
    generate_input_file();
    generate_output_file();
    return 0;
}