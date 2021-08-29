#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

int main()
{
	int n;
	cin >> n;
	unordered_map<string, int> mp;
	rep (i, n)
	{
		string s, t;
		cin >> s >> t;
		mp[s + ' ' + t]++;
	}

	bool ok = false;
	for (const auto& i : mp)
		if (i.second > 1)
			ok = true;
	cout << (ok ? "Yes" : "No") << endl;
	return 0;
}