#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

filesystem::path p = filesystem::current_path();

const int max_len = 12;

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

int n, m;
vector<string> s;
vector<string> ans;

//_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

int generate_output()
{
    ofstream ofs(p.parent_path().string<char>() + "/output.txt");
    if (!ofs)
        return -1;
    for (auto str : ans)
        ofs << str << endl;
    return 0;
}

int calc_score(vector<string> ans)
{
    vector<string> vertical_ans(n), holizontal_ans(n);
    rep (i, n)
        holizontal_ans[i] = ans[i] + ans[i];
    rep (i, n)
        rep (j, n)
            vertical_ans[i] += ans[j][i];

    set<string> st;
    for (string str : vertical_ans)
    {
        str += str;
        rep (i, n * 2)
            for (int j = 2; j <= max_len; j++)
                st.insert(str.substr(i, j));
    }
    for (string str : holizontal_ans)
    {
        str += str;
        rep (i, n * 2)
            for (int j = 2; j <= max_len; j++)
                st.insert(str.substr(i, j));
    }

    int cnt = 0;
    for (string str : s)
    {
        if (st.find(str) == st.end())
            continue;
        cnt++;
    }

    return round(1e8 * double(cnt) / m);
}

//_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

int main()
{
    cin >> n >> m;
    s.resize(m);
    ans.resize(n);
    rep (i, m)
    {
        string str;
        cin >> str;
        s.push_back(str);
    }

    ProcessingTime time;
    int score = -1;
    int loop_cnt = 0;
    while (time.get_elapsed() < 2950)
    {
        vector<string> candidate(n);
        rep (i, n)
            rep (j, n)
            {
                auto rand_num = get_rand() % 8;
                candidate[i] += (rand_num == 8 ? '.' : 'A' + rand_num);
            }

        int candidate_score = calc_score(candidate);
        if (candidate_score > score)
        {
            ans = candidate;
            score = candidate_score;
        }
        loop_cnt++;
    }
    for (auto str : ans)
        cout << str << endl;
    generate_output();
    return 0;
}