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
    size_t operator()(const std::pair<int, int>& x) const
    {
        return hash<int>()(x.first) ^ hash<int>()(x.second);
    }
};
}  // namespace std

struct Cost
{
    int estimated_cost;
    int cost_sum;
    int cnt;
};

struct Edge
{
    int sx, sy;
    int gx, gy;
};

const int INF = 1e9;

unordered_map<pair<int, int>, unordered_map<pair<int, int>, Cost>> graph;
vector<Edge> history;
int si, sj, ti, tj;
int cost;

void init_graph()
{
    rep (i, 30)
        rep (j, 30 - 1)
            graph[make_pair(i, j)][make_pair(i, j + 1)] = Cost{0, 0, 0}, graph[make_pair(i, j + 1)][make_pair(i, j)] = Cost{0, 0, 0};
    rep (i, 30 - 1)
        rep (j, 30)
            graph[make_pair(i, j)][make_pair(i + 1, j)] = Cost{0, 0, 0}, graph[make_pair(i + 1, j)][make_pair(i, j)] = Cost{0, 0, 0};
    return;
}

char get_direction(int si, int sj, int nx, int ny)
{
    int x_diff = nx - sj;
    int y_diff = ny - si;

    if (x_diff > 0)
        return 'R';
    else if (x_diff < 0)
        return 'L';
    else if (y_diff > 0)
        return 'D';
    else
        return 'U';
}

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
string get_route()
{
    string ret;

    while (si != ti || sj != tj)
    {
        pair<int, int> dest;
        int min_cost = INF;
        char dir;
        rep (d, 4)
        {
            int nx = sj + dx[d];
            int ny = si + dy[d];
            if (abs(tj - nx) > abs(tj - sj))
                continue;
            if (abs(ti - ny) > abs(ti - si))
                continue;

            if (graph[make_pair(sj, si)][make_pair(nx, ny)].estimated_cost < min_cost)
            {
                dest.first = nx;
                dest.second = ny;
                min_cost = graph[make_pair(sj, si)][make_pair(nx, ny)].estimated_cost;
                dir = get_direction(si, sj, nx, ny);
            }
        }
        history.push_back(Edge{sj, si, dest.first, dest.second});
        ret += dir;
        sj = dest.first;
        si = dest.second;
    }

    return ret + '\n';
}

void update_graph()
{
    int move_cnt = history.size();
    int avg_cost = round((double)cost / move_cnt);
    for (auto p : history)
    {
        graph[make_pair(p.sx, p.sy)][make_pair(p.gx, p.gy)].cost_sum += avg_cost;
        graph[make_pair(p.sx, p.sy)][make_pair(p.gx, p.gy)].cnt++;
        graph[make_pair(p.sx, p.sy)][make_pair(p.gx, p.gy)].estimated_cost = round((double)graph[make_pair(p.sx, p.sy)][make_pair(p.gx, p.gy)].cost_sum / graph[make_pair(p.sx, p.sy)][make_pair(p.gx, p.gy)].cnt);
        graph[make_pair(p.gx, p.gy)][make_pair(p.sx, p.sy)].cost_sum += avg_cost;
        graph[make_pair(p.gx, p.gy)][make_pair(p.sx, p.sy)].cnt++;
        graph[make_pair(p.gx, p.gy)][make_pair(p.sx, p.sy)].estimated_cost = round((double)graph[make_pair(p.gx, p.gy)][make_pair(p.sx, p.sy)].cost_sum / graph[make_pair(p.gx, p.gy)][make_pair(p.sx, p.sy)].cnt);
    }
    history.clear();
}

int main()
{
    init_graph();

    rep (i, 1000)
    {
        cin >> si >> sj >> ti >> tj;
        cout << get_route() << flush;
        cin >> cost;
        update_graph();
    }

    return 0;
}