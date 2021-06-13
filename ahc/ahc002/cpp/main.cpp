#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

const int MAX_NUM = 50;

int sx, sy;
vector<vector<int>> t;
vector<vector<int>> p;

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

struct Tile
{
    vector<vector<bool>> seen;
    vector<vector<pair<int, int>>> same_tile;
    string ans;
    int score;

    Tile();
    void init_soln();
    void rand_soln();
    void generate_output_file();
};

Tile::Tile()
{
    seen.resize(MAX_NUM), same_tile.resize(MAX_NUM * MAX_NUM);
    rep (i, MAX_NUM)
        seen[i].resize(MAX_NUM, false);

    rep (i, MAX_NUM)
        rep (j, MAX_NUM)
            same_tile[t[i][j]].push_back(make_pair(i, j));

    score = p[sx][sy];
}

void Tile::init_soln()
{
    const int dx[4] = {1, 0, -1, 0};
    const int dy[4] = {0, 1, 0, -1};
    queue<pair<int, int>> que;
    que.push(make_pair(sx, sy));
    for (pair<int, int> p : same_tile[t[sx][sy]])
        seen[p.first][p.second] = true;

    while (!que.empty())
    {
        pair<int, int> currentPos = que.front();
        int x = currentPos.first;
        int y = currentPos.second;
        que.pop();

        rep (d, 4)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || nx >= MAX_NUM || ny < 0 || ny >= MAX_NUM)
                continue;
            if (seen[nx][ny])
                continue;

            if (!seen[nx][ny])
            {
                que.push(make_pair(nx, ny));
                for (pair<int, int> p : same_tile[t[nx][ny]])
                    seen[p.first][p.second] = true;
                switch (d)
                {
                    case 0:
                        ans += 'D';
                        break;
                    case 1:
                        ans += 'R';
                        break;
                    case 2:
                        ans += 'U';
                        break;
                    case 3:
                        ans += 'L';
                        break;
                    default:
                        break;
                }
                score += p[nx][ny];
                break;
            }
        }
    }
}

void Tile::rand_soln()
{
    const int dx[4] = {1, 0, -1, 0};
    const int dy[4] = {0, 1, 0, -1};
    queue<pair<int, int>> que;
    que.push(make_pair(sx, sy));
    for (pair<int, int> p : same_tile[t[sx][sy]])
        seen[p.first][p.second] = true;

    while (!que.empty())
    {
        pair<int, int> currentPos = que.front();
        int x = currentPos.first;
        int y = currentPos.second;
        que.pop();

        for (int d = get_rand() % 4, cnt = 0; cnt < 4; d = (d + 1) % 4, cnt++)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || nx >= MAX_NUM || ny < 0 || ny >= MAX_NUM)
                continue;
            if (seen[nx][ny])
                continue;

            if (!seen[nx][ny])
            {
                que.push(make_pair(nx, ny));
                for (pair<int, int> p : same_tile[t[nx][ny]])
                    seen[p.first][p.second] = true;
                switch (d)
                {
                    case 0:
                        ans += 'D';
                        break;
                    case 1:
                        ans += 'R';
                        break;
                    case 2:
                        ans += 'U';
                        break;
                    case 3:
                        ans += 'L';
                        break;
                    default:
                        break;
                }
                score += p[nx][ny];
                break;
            }
        }
    }
}

void Tile::generate_output_file()
{
    ofstream ofs(filesystem::current_path().parent_path().string<char>() + "/out.txt");
    if (!ofs)
        return;
    ofs << ans << endl;
    return;
}

void input()
{
    t.resize(MAX_NUM), p.resize(MAX_NUM);
    rep (i, MAX_NUM)
        t[i].resize(MAX_NUM), p[i].resize(MAX_NUM);

    cin >> sx >> sy;
    rep (i, MAX_NUM)
        rep (j, MAX_NUM)
            cin >> t[i][j];
    rep (i, MAX_NUM)
        rep (j, MAX_NUM)
            cin >> p[i][j];
}

int main()
{
    input();
    ProcessingTime time;
    Tile tile;
    tile.init_soln();
    string ans = tile.ans;
    int score = tile.score;
    int cnt;
    while (time.get_elapsed() < 1980)
    {
        Tile temp;
        temp.rand_soln();
        if (temp.score > score)
            ans = temp.ans, score = temp.score;
        cnt++;
    }
    cout << ans << endl;
    return 0;
}