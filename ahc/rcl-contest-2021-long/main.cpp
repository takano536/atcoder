#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

//_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

filesystem::path p = filesystem::current_path();

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

void get_answer(const int n, const int m, const int t, vector<VeggieInfo>& veggies, vector<vector<int>>& ans)
{
    set<VeggieInfo, greater<VeggieInfo>> harvested_veggies;
    vector<VeggieInfo> s_sorted_veggies = veggies;
    sort(s_sorted_veggies.begin(), s_sorted_veggies.end(), [](const VeggieInfo& p, const VeggieInfo& q) { return p.s != q.s ? p.s < q.s : p.e < q.e; });
    auto grow_iter = s_sorted_veggies.begin();
    vector<VeggieInfo> e_sorted_veggies = veggies;
    sort(e_sorted_veggies.begin(), e_sorted_veggies.end(), [](const VeggieInfo& p, const VeggieInfo& q) { return p.e != q.e ? p.e < q.e : p.s < q.s; });
    auto die_iter = e_sorted_veggies.begin();

    vector<Machine> machines;
    int fund = 1;
    int price = 1;
    int harvest_amount = 0;

    for (int date = 0; date < t; date++)
    {
        while (grow_iter != s_sorted_veggies.end() && grow_iter->s <= date)
        {
            // 生えた野菜の更新
            harvested_veggies.insert(*grow_iter);
            grow_iter++;
        }

        // 行動の選択
        if (harvested_veggies.size() > 0 && price == 1)
        {
            // 収穫機の購入
            VeggieInfo target_veggie = *harvested_veggies.begin();
            harvested_veggies.erase(harvested_veggies.begin());
            ans[date].push_back(target_veggie.y), ans[date].push_back(target_veggie.x);
            machines.push_back({static_cast<int>(machines.size()), target_veggie.y, target_veggie.x});
            price = pow(machines.size() + 1, 3);
        }
        else if (harvested_veggies.size() > 0)
        {
            // 収穫機の移動
            VeggieInfo target_veggie = *harvested_veggies.begin();
            harvested_veggies.erase(harvested_veggies.begin());
            ans[date].push_back(machines[0].y), ans[date].push_back(machines[0].x), ans[date].push_back(target_veggie.y), ans[date].push_back(target_veggie.x);
            machines[0].x = target_veggie.x, machines[0].y = target_veggie.y;
        }
        else
        {
            ans[date].push_back(-1);
        }

        while (die_iter != e_sorted_veggies.end() && die_iter->e <= date)
        {
            // 枯れた野菜の更新
            harvested_veggies.erase(*die_iter);
            die_iter++;
        }
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

int generate_output_file(const vector<vector<int>>& ans)
{
    ofstream ofs(p.parent_path().string<char>() + "/rcl-contest-2021-long/tools/tester/output.txt");
    if (!ofs)
        return -1;
    for (const auto& v : ans)
    {
        for (auto iter = v.begin(); iter != v.end(); iter++)
            if (iter + 1 != v.end())
                ofs << *iter << ' ';
            else
                ofs << *iter << endl;
    }
    return 0;
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
    generate_output_file(ans);
    return 0;
}