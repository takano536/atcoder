#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

//_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

struct Cost
{
    int estimated_cost;
    double cost_sum;
    int cnt;
};

struct Edge
{
    int cost;
    int sx, sy;
    int gx, gy;
};
bool operator>(const Edge &edge1, const Edge &edge2)
{
    return edge1.cost > edge2.cost;
};

//_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

const int INF = 1e9;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

Cost graph[30][30][30][30];
vector<Edge> history;
int si, sj, ti, tj;
int cost;

//_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

void init_graph(int value)
{
    rep (i, 30)
        rep (j, 30 - 1)
            graph[i][j][i][j + 1] = Cost{value, 0, 0}, graph[i][j + 1][i][j] = Cost{value, 0, 0};
    rep (i, 30 - 1)
        rep (j, 30)
            graph[i][j][i + 1][j] = Cost{value, 0, 0}, graph[i + 1][j][i][j] = Cost{value, 0, 0};
}

void dijkstra(int (&dist)[30][30], pair<int, int> (&prev)[30][30])
{
    rep (i, 30)
        rep (j, 30)
            dist[i][j] = INF;
    rep (i, 30)
        rep (j, 30)
            prev[i][j] = make_pair(-1, -1);

    priority_queue<Edge, vector<Edge>, greater<Edge>> que;
    dist[sj][si] = 0;
    que.push(Edge{dist[sj][si], sj, si, (int)NULL, (int)NULL});

    while (!que.empty())
    {
        auto edge = que.top();
        que.pop();
        rep (d, 4)
        {
            int cur_x = edge.sx + dx[d];
            int cur_y = edge.sy + dy[d];
            if (cur_x < 0 || cur_x >= 30)
                continue;
            if (cur_y < 0 || cur_y >= 30)
                continue;

            int cur_dist = dist[edge.sx][edge.sy] + graph[edge.sx][edge.sy][cur_x][cur_y].estimated_cost;
            if (cur_dist >= dist[cur_x][cur_y])
                continue;
            dist[cur_x][cur_y] = cur_dist;
            prev[cur_x][cur_y] = make_pair(edge.sx, edge.sy);
            que.push(Edge{dist[cur_x][cur_y], cur_x, cur_y, (int)NULL, (int)NULL});
        }
    }
}

char get_dir(int sx, int sy, int cur_x, int cur_y)
{
    int x_diff = cur_x - sx;
    int y_diff = cur_y - sy;

    if (x_diff > 0)
        return 'R';
    else if (x_diff < 0)
        return 'L';
    else if (y_diff > 0)
        return 'D';
    else
        return 'U';
}

string get_path(const pair<int, int> (&prev)[30][30])
{
    string path;

    pair<int, int> dest = make_pair(tj, ti);
    for (auto cur = dest; prev[cur.first][cur.second].first != -1; cur = prev[cur.first][cur.second])
    {
        path += get_dir(prev[cur.first][cur.second].first, prev[cur.first][cur.second].second, cur.first, cur.second);
        history.push_back(Edge{(int)NULL, prev[cur.first][cur.second].first, prev[cur.first][cur.second].second, cur.first, cur.second});
    }
    reverse(path.begin(), path.end());

    return path + '\n';
}

void update_graph()
{
    int move_cnt = history.size();
    double avg_cost = (double)cost / move_cnt;
    for (auto edge : history)
    {
        graph[edge.sx][edge.sy][edge.gx][edge.gy].cost_sum += avg_cost;
        graph[edge.gx][edge.gy][edge.sx][edge.sy].cost_sum += avg_cost;
        graph[edge.sx][edge.sy][edge.gx][edge.gy].cnt++;
        graph[edge.gx][edge.gy][edge.sx][edge.sy].cnt++;

        double cost_sum = graph[edge.sx][edge.sy][edge.gx][edge.gy].cost_sum;
        int cnt = graph[edge.sx][edge.sy][edge.gx][edge.gy].cnt;
        int estimated_cost = round(cost_sum / cnt);
        graph[edge.sx][edge.sy][edge.gx][edge.gy].estimated_cost = estimated_cost;
        graph[edge.gx][edge.gy][edge.sx][edge.sy].estimated_cost = estimated_cost;
    }
    history.clear();
}

//_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

int main()
{
    init_graph(1);

    int dist[30][30];
    pair<int, int> prev[30][30];
    rep (i, 1000)
    {
        cin >> si >> sj >> ti >> tj;
        dijkstra(dist, prev);
        cout << get_path(prev) << flush;

        cin >> cost;
        update_graph();
    }

    return 0;
}