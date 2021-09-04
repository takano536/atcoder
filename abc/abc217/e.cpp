#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

int main()
{
    int q;
    cin >> q;
    queue<int> que;
    priority_queue<int, vector<int>, greater<int>> priority_que;
    rep (i, q)
    {
        int c;
        cin >> c;
        switch (c)
        {
            case 1:
                int x;
                cin >> x;
                que.push(x);
                break;

            case 2:
                if (!priority_que.empty())
                    cout << priority_que.top() << endl, priority_que.pop();
                else
                    cout << que.front() << endl, que.pop();
                break;

            case 3:
                while (!que.empty())
                    priority_que.push(que.front()), que.pop();
                break;
        }
    }
    return 0;
}