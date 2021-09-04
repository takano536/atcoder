#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

int main()
{
	map<string, bool> ok;
    ok["ABC"] = false;
    ok["ARC"] = false;
    ok["AGC"] = false;
    ok["AHC"] = false;
	rep (i, 3)
	{
		string s;
		cin >> s;
		ok[s] = true;
	}

	for (const auto& p : ok)
        if (!p.second)
            cout << p.first << endl;
	return 0;
}