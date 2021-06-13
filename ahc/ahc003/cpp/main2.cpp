#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

namespace std
{
template <>
class hash<std::pair<int, int>>
{
   public:
    size_t operator()(const std::pair<int, int> &x) const
    {
        return hash<int>()(x.first) ^ hash<int>()(x.second);
    }
};
}  // namespace std

//_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

struct Cost
{
    int estimated_cost;
    int cost_sum;
    int cnt;
};

struct Edge
{
    int cost;
    int sx, sy;
    int gx, gy;
};
bool operator>(const Edge &Edge1, const Edge &Edge2)
{
    return Edge1.cost > Edge2.cost;
};

//_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

const int INF = 1e9;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

unordered_map<pair<int, int>, unordered_map<pair<int, int>, Cost>> graph;
vector<Edge> history;
int si, sj, ti, tj;
int cost;

//_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

void init_graph()
{
    rep (i, 30)
        rep (j, 30 - 1)
        {
            graph[make_pair(i, j)][make_pair(i, j + 1)] = Cost{1, 0, 0};
            graph[make_pair(i, j + 1)][make_pair(i, j)] = Cost{1, 0, 0};
        }
    rep (i, 30 - 1)
        rep (j, 30)
        {
            graph[make_pair(i, j)][make_pair(i + 1, j)] = Cost{1, 0, 0};
            graph[make_pair(i + 1, j)][make_pair(i, j)] = Cost{1, 0, 0};
        }
}

void dijkstra(unordered_map<pair<int, int>, int> &dist, unordered_map<pair<int, int>, pair<int, int>> &prev)
{
    rep (i, 30)
        rep (j, 30)
            dist[make_pair(i, j)] = INF;
    rep (i, 30)
        rep (j, 30)
            prev[make_pair(i, j)] = make_pair(-1, -1);

    priority_queue<Edge, vector<Edge>, greater<Edge>> que;
    dist[make_pair(sj, si)] = 0;
    que.push(Edge{dist[make_pair(sj, si)], sj, si, (int)NULL, (int)NULL});

    while (!que.empty())
    {
        auto edge = que.top();
        que.pop();
        rep (d, 4)
        {
            int cur_x = edge.sx + dx[d];
            int cur_y = edge.sy + dy[d];
            if (cur_x < max(min(sj, tj) - 10, 0) || cur_x > min(max(sj, tj) + 10, 30))
                continue;
            if (cur_y < max(min(si, ti) - 10, 0) || cur_y > min(max(si, ti) + 10, 30))
                continue;

            int cur_dist = dist[make_pair(edge.sx, edge.sy)] + graph[make_pair(edge.sx, edge.sy)][make_pair(cur_x, cur_y)].estimated_cost;
            if (cur_dist < dist[make_pair(cur_x, cur_y)])
            {
                dist[make_pair(cur_x, cur_y)] = cur_dist;
                prev[make_pair(cur_x, cur_y)] = make_pair(edge.sx, edge.sy);
                que.push(Edge{dist[make_pair(cur_x, cur_y)], cur_x, cur_y, (int)NULL, (int)NULL});
            }
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

string get_path(unordered_map<pair<int, int>, pair<int, int>> &prev)
{
    string path;

    pair<int, int> dest = make_pair(tj, ti);
    for (auto cur = dest; prev[cur].first != -1; cur = prev[cur])
    {
        path += get_dir(prev[cur].first, prev[cur].second, cur.first, cur.second);
        history.push_back(Edge{(int)NULL, prev[cur].first, prev[cur].second, cur.first, cur.second});
    }
    reverse(path.begin(), path.end());

    return path + '\n';
}

void update_graph()
{
    int move_cnt = history.size();
    int avg_cost = round((double)cost / move_cnt);
    for (auto p : history)
    {
        graph[make_pair(p.sx, p.sy)][make_pair(p.gx, p.gy)].cost_sum += avg_cost;
        graph[make_pair(p.gx, p.gy)][make_pair(p.sx, p.sy)].cost_sum += avg_cost;
        graph[make_pair(p.sx, p.sy)][make_pair(p.gx, p.gy)].cnt++;
        graph[make_pair(p.gx, p.gy)][make_pair(p.sx, p.sy)].cnt++;

        double cost_sum = graph[make_pair(p.sx, p.sy)][make_pair(p.gx, p.gy)].cost_sum;
        int cnt = graph[make_pair(p.sx, p.sy)][make_pair(p.gx, p.gy)].cnt;
        int estimated_cost = round(cost_sum / cnt);
        graph[make_pair(p.sx, p.sy)][make_pair(p.gx, p.gy)].estimated_cost = estimated_cost;
        graph[make_pair(p.gx, p.gy)][make_pair(p.sx, p.sy)].estimated_cost = estimated_cost;
    }
    history.clear();
}

//_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

int main()
{
    init_graph();

    rep (i, 1000)
    {
        cin >> si >> sj >> ti >> tj;
        unordered_map<pair<int, int>, int> dist;
        unordered_map<pair<int, int>, pair<int, int>> prev;
        dijkstra(dist, prev);
        cout << get_path(prev) << flush;

        cin >> cost;
        update_graph();
    }

    return 0;
}