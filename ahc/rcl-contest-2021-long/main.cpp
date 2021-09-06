#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

//_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

struct VeggieInfo
{
    int r, c, s, e, v;
};

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

void receive_input(vector<VeggieInfo>& veggies)
{
    for (auto& veggie : veggies)
        cin >> veggie.r >> veggie.c >> veggie.s >> veggie.e >> veggie.v;
}

//_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

void get_answer(const tuple<int, int, int>& constant, vector<VeggieInfo>& veggies, vector<vector<int>>& ans)
{
    for (auto& v : ans)
        v.push_back(-1);
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
    get_answer({n, m, t}, veggies, ans);

    output_answer(ans);
    // generate_output_file(ans);
    return 0;
}