#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

const int MAXDATA = 200200;
vector<set<int>> graph(MAXDATA);
vector<bool> seen(MAXDATA, false);
vector<int> ans;

void dfs(int sv)
{
    seen[sv] = true;
    ans.push_back(sv + 1);
    for (auto nv : graph[sv])
    {
        if (seen[nv])
            continue;
        dfs(nv);
        ans.push_back(sv + 1);
    }
}

int main()
{
    int n;
    cin >> n;
    rep (i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        graph[a].insert(b);
        graph[b].insert(a);
    }

    dfs(0);
    
    for (auto i : ans)
        cout << i << ' ';
    cout << endl;
    return 0;
}