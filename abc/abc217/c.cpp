#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

int main()
{
	int n;
	cin >> n;
	vector<int> p(n);
	rep (i, n)
		cin >> p[i];

	vector<int> ans(n);
	rep (i, n)
		ans[p[i] - 1] = i + 1;
	for (const auto& i : ans)
		cout << i << ' ';
	cout << endl;
	return 0;
}