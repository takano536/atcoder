#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

struct Cell
{
    int cost;
    int x, y;
};
bool operator>(const Cell &p, const Cell &q)
{
    return p.cost > q.cost;
};

const int INF = 1001001001;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int bfs(const vector<string> &field, int sx, int sy)
{
    int width = field[0].size();
    int height = field.size();

    vector cost(width, vector<int>(height, INF));  // 破壊回数
    cost[sx][sy] = 0;
    priority_queue<Cell, vector<Cell>, greater<Cell>> que;
    que.push(Cell{0, sx, sy});

    while (!que.empty())
    {
        Cell cur_pos = que.top();
        int cur_cost = cur_pos.cost;
        int cur_x = cur_pos.x;
        int cur_y = cur_pos.y;
        que.pop();

        rep (d, 4)
        {
            int nx = cur_x + dx[d];
            int ny = cur_y + dy[d];
            if (nx < 0 || nx >= width || ny < 0 || ny >= height)
                continue;
            if (field[ny][nx] == '#')
                continue;

            if (cost[cur_x][cur_y] < cost[nx][ny])
            {
                cost[nx][ny] = cost[cur_x][cur_y];
                que.push(Cell{cost[nx][ny], nx, ny});
            }
        }
        for (int dx = -2; dx <= 2; dx++)
            for (int dy = -2; dy <= 2; dy++)
            {
                if (abs(dx) + abs(dy) > 3)
                    continue;

                int nx = cur_x + dx;
                int ny = cur_y + dy;
                if (nx < 0 || nx >= width || ny < 0 || ny >= height)
                    continue;

                if (cost[cur_x][cur_y] + 1 < cost[nx][ny])
                {
                    cost[nx][ny] = cost[cur_x][cur_y] + 1;
                    que.push(Cell{cost[nx][ny], nx, ny});
                }
            }
    }
    return cost[width - 1][height - 1];
}

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> f(h);
    rep (i, h)
        cin >> f[i];

    cout << bfs(f, 0, 0) << endl;
    return 0;
}