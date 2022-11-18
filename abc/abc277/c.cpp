#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

int bfs(const map<int, vector<int>> &graph, int sv)
{
    int n = graph.size();
    map<int, bool> is_saw;
    queue<int> que;
    is_saw[sv] = true;
    que.push(sv);
    int ans = sv;
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        if (graph.find(v) == graph.end())
            continue;
        for (auto nv : graph.at(v)) {
            if (is_saw[nv])
                continue;
            is_saw[nv] = true;
            que.push(nv);
            ans = max(nv, ans);
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    map<int, vector<int>> graph;
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    cout << bfs(graph, 1) << endl;
    return 0;
}