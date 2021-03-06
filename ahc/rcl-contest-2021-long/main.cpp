#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

//_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

random_device rd;
static std::mt19937_64 mt64(rd());
uint64_t get_rand()
{
    return mt64();
}

class ProcessingTime
{
public:
    ProcessingTime()
    {
        start = chrono::system_clock::now();
    }
    int64_t get_elapsed()
    {
        const auto end = std::chrono::system_clock::now();
        return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    }

private:
    std::chrono::system_clock::time_point start;
};

//_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

struct VeggieInfo
{
    int id;
    int y, x, s, e, v;
    bool operator<(const VeggieInfo& right) const
    {
        if (this->v != right.v)
            return this->v < right.v;
        if (this->s != right.s)
            return this->s < right.s;
        if (this->e != right.e)
            return this->e < right.e;
        if (this->x != right.x)
            return this->x < right.x;
        return this->y < right.y;
    }
    bool operator>(const VeggieInfo& right) const
    {
        if (this->v != right.v)
            return this->v > right.v;
        if (this->s != right.s)
            return this->s < right.s;
        if (this->e != right.e)
            return this->e < right.e;
        if (this->x != right.x)
            return this->x < right.x;
        return this->y < right.y;
    }
};

//_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

struct Machine
{
    int id;
    int y, x;

    Machine(int id, int y, int x)
    {
        this->id = id;
        this->y = y;
        this->x = x;
    }
};

//_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

void receive_input(vector<VeggieInfo>& veggies)
{
    int cnt = 0;
    for (auto& veggie : veggies)
        cin >> veggie.y >> veggie.x >> veggie.s >> veggie.e >> veggie.v, veggie.id = cnt++;
}

//_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

// ????????????????????????????????????????????????????????????????????????????????????????????????
void get_answer(const int n, const int m, const int t, vector<VeggieInfo>& veggies, vector<vector<int>>& ans)
{
    set<VeggieInfo, greater<VeggieInfo>> grow_veggies;  // ????????????????????????????????????????????????????????????

    VeggieInfo veggies_map[n + 1][n + 1];  // key ??? ????????? map
    rep (i, n + 1)
        rep (j, n + 1)
            veggies_map[i][j] = {-1, -1, -1, -1, -1};

    vector<VeggieInfo> s_sorted_veggies = veggies;  //???grow_veggies ?????????
    sort(s_sorted_veggies.begin(), s_sorted_veggies.end(), [](const VeggieInfo& p, const VeggieInfo& q) { return p.s != q.s ? p.s < q.s : p.e < q.e; });
    auto grow_iter = s_sorted_veggies.begin();
    vector<VeggieInfo> e_sorted_veggies = veggies;  //???grow_veggies ?????????
    sort(e_sorted_veggies.begin(), e_sorted_veggies.end(), [](const VeggieInfo& p, const VeggieInfo& q) { return p.e != q.e ? p.e < q.e : p.s < q.s; });
    auto die_iter = e_sorted_veggies.begin();

    vector<Machine> machines;
    pair<int, int> next_install_coord = make_pair(0, 0);    // ?????????????????????????????????????????????????????????
    pair<int, int> move_machine_coord = make_pair(-1, -1);  // ????????????????????????????????????
    vector<vector<bool>> is_installed(n, vector<bool>(n, false));

    const int MAX_MACHINE_NUM = 30;
    int money = 1;
    int price = 1;
    int today_profit = 0;

    for (int date = 0; date < t; date++)
    {
        today_profit = 0;

        // ????????????????????????
        while (grow_iter != s_sorted_veggies.end() && grow_iter->s <= date)
        {
            if (is_installed[grow_iter->y][grow_iter->x] && move_machine_coord != make_pair(grow_iter->y, grow_iter->x))
            {
                // ???????????????????????????
                today_profit += grow_iter->v * (machines.size() - 1);
            }
            else
            {
                veggies_map[grow_iter->y][grow_iter->x] = *grow_iter;
                grow_veggies.insert(*grow_iter);
            }
            grow_iter++;
        }

        // ???????????????
        bool is_acted = false;
        if (grow_veggies.size() > 0 && machines.size() == 0)
        {
            // ??????????????????????????????
            auto veggie = *grow_veggies.begin();
            grow_veggies.erase(grow_veggies.begin());
            ans[date].push_back(veggie.y), ans[date].push_back(veggie.x);
            machines.push_back({static_cast<int>(machines.size()), veggie.y, veggie.x});
            grow_veggies.erase(veggies_map[veggie.y][veggie.x]);
            veggies_map[veggie.y][veggie.x] = {-1, -1, -1, -1, -1};
            is_installed[veggie.y][veggie.x] = true;
            today_profit -= price;
            today_profit += veggie.v;
            price = pow(machines.size() + 1, 3);
            is_acted = true;
        }
        else if (machines.size() < MAX_MACHINE_NUM && money >= price && !is_installed[next_install_coord.first][next_install_coord.second])
        {
            // ??????????????????
            ans[date].push_back(next_install_coord.first), ans[date].push_back(next_install_coord.second);
            machines.push_back({static_cast<int>(machines.size()), next_install_coord.first, next_install_coord.second});

            if (veggies_map[next_install_coord.first][next_install_coord.second].id != -1)
            {
                // ????????????????????????
                today_profit += veggies_map[next_install_coord.first][next_install_coord.second].v * (machines.size() - 1);
                grow_veggies.erase(veggies_map[next_install_coord.first][next_install_coord.second]);
                veggies_map[next_install_coord.first][next_install_coord.second] = {-1, -1, -1, -1, -1};
            }

            is_installed[next_install_coord.first][next_install_coord.second] = true;
            next_install_coord.second = (next_install_coord.second + 1) % n;
            next_install_coord.first = (next_install_coord.second == 0 ? next_install_coord.first + 1 : next_install_coord.first);
            today_profit -= price;
            price = pow(machines.size() + 1, 3);
            is_acted = true;
        }
        else if (grow_veggies.size() > 0)
        {
            // ??????????????????
            auto veggie = *grow_veggies.begin();
            bool has_found = false;
            for (auto iter = grow_veggies.begin(); iter != grow_veggies.end(); iter++)
            {
                if (!is_installed[iter->y][iter->x])
                {
                    veggie = *iter;
                    grow_veggies.erase(iter);
                    has_found = true;
                    break;
                }
            }
            if (has_found)
            {
                ans[date].push_back(machines[0].y), ans[date].push_back(machines[0].x), ans[date].push_back(veggie.y), ans[date].push_back(veggie.x);
                grow_veggies.erase(veggies_map[veggie.y][veggie.x]);
                veggies_map[veggie.y][veggie.x] = {-1, -1, -1, -1, -1};
                is_installed[machines[0].y][machines[0].x] = false;
                is_installed[veggie.y][veggie.x] = true;
                machines[0].y = veggie.y, machines[0].x = veggie.x;
                move_machine_coord.first = veggie.y, move_machine_coord.second = veggie.x;
                today_profit += veggie.v;
                is_acted = true;
            }
        }
        if (!is_acted)
        {
            // ???????????????
            ans[date].push_back(-1);
        }

        // ????????????????????????
        while (die_iter != e_sorted_veggies.end() && die_iter->e <= date)
        {
            veggies_map[die_iter->y][die_iter->x] = {-1, -1, -1, -1, -1};
            grow_veggies.erase(*die_iter);
            die_iter++;
        }
        money += today_profit;
    }
}

//_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

void output_answer(const vector<vector<int>>& ans)
{
    for (const auto& v : ans)
    {
        for (auto iter = v.begin(); iter != v.end(); iter++)
            if (iter + 1 != v.end())
                cout << *iter << ' ';
            else
                cout << *iter << endl;
    }
}

//_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

int main()
{
    int n, m, t;
    cin >> n >> m >> t;
    vector<VeggieInfo> veggies(m);
    receive_input(veggies);

    vector<vector<int>> ans(t);
    get_answer(n, m, t, veggies, ans);

    output_answer(ans);
    return 0;
}