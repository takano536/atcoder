#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

#include <chrono>

filesystem::path p = filesystem::current_path();
double TIME_LIMIT = 4.0f;
int INF = 1e9;

struct advertisement
{
    int x, y;
    int r;
    int num;
    int a, b, c, d;
};
bool num_asc(const advertisement& left, const advertisement& right)
{
    return left.num < right.num;
}
bool r_asc(const advertisement& left, const advertisement& right)
{
    return left.r == right.r ? left.num < right.num : left.r < right.r;
}
bool x_asc(const advertisement& left, const advertisement& right)
{
    return left.x == right.x ? left.y < right.y : left.x < right.x;
}
bool y_asc(const advertisement& left, const advertisement& right)
{
    return left.y == right.y ? left.x < right.x : left.y < right.y;
}

int n;
vector<advertisement> ad;
vector<vector<bool>> exists(10001, vector<bool>(10001, false));

uint64_t get_rand(uint64_t min_val, uint64_t max_val)
{
    static std::mt19937_64 mt64(0);
    std::uniform_int_distribution<uint64_t> get_rand_uni_int(min_val, max_val);
    return get_rand_uni_int(mt64);
}

int generate_input_file()
{
    ofstream ofs(p.parent_path().string<char>() + "/tools/src/bin/out/input.txt");
    if (!ofs)
        return -1;
    ofs << n << endl;
    rep (i, n)
        ofs << ad[i].x << ' ' << ad[i].y << ' ' << ad[i].r << endl;
    return 0;
}

int generate_output_file()
{
    ofstream ofs(p.parent_path().string<char>() + "/tools/src/bin/out/output.txt");
    if (!ofs)
        return -1;
    rep (i, n)
        ofs << ad[i].a << ' ' << ad[i].b << ' ' << ad[i].c << ' ' << ad[i].d << endl;
    return 0;
}

int calculate_score(vector<advertisement> target_ad)
{
    long double sum = 0;
    rep (i, n)
    {
        int s = (target_ad[i].c - target_ad[i].a) * (target_ad[i].d - target_ad[i].b);
        long double p = 1 - (1 - double(min(target_ad[i].r, s)) / max(target_ad[i].r, s)) * (1 - double(min(target_ad[i].r, s)) / max(target_ad[i].r, s));
        sum += p;
    }
    return round(sum / n * 1e9);
}

bool is_ng(int a, int b, int c, int d)
{
    for (int i = a; i <= c; i++)
        for (int j = b; j <= d; j++)
            if (exists[i][j])
                return true;     
    return (c - a) * (d - b) <= 0;
}

void update_exists(int a, int b, int c, int d)
{
    for (int i = a; i <= c; i++)
        for (int j = b; j <= d; j++)
            exists[i][j] = true;
}

void place_ad()
{
    sort(ad.begin(), ad.end(), x_asc);
    rep (i, n)
    {
        exists[ad[i].x][ad[i].y] = false;
        int a, b, c, d;
        do
        {
            int width = get_rand(1, min(ad[i].r, 10000 - 1));
            int height = round((double)ad[i].r / width);
            if (width > 10000 || height > 10000)
                continue;
            a = ad[i].x - get_rand(0, width - 1), a = max(a, 0), a = min(a, 10000 - width);
            b = ad[i].y - get_rand(0, height - 1), b = max(b, 0), b = min(b, 10000 - height);
            bool ng = false;
            for (int j = a; j <= a + width; j++)
            {
                for (int k = b; k <= b + height; k++)
                    if (exists[j][k])
                    {
                        c = j - 1;
                        d = k - 1;
                        ng = true;
                        break;
                    }
                if (ng)
                    break;
            }
        } while (is_ng(a, b, c, d));
        ad[i].a = a, ad[i].b = b, ad[i].c = c, ad[i].d = d;
        update_exists(a, b, c, d);
    }
}

int modify(vector<advertisement> target_ad, vector<vector<bool>> target_exists)
{
}

void sa(vector<advertisement> target_ad)
{
    vector<vector<bool>> pre_exists(10001, vector<bool>(10001, false));
    vector<advertisement> pre_ad = target_ad;
    rep (i, n)
        for (int j = pre_ad[i].a; j <= pre_ad[i].c; j++)
            for (int k = pre_ad[i].b; k <= pre_ad[i].d; k++)
                pre_exists[j][k] = true;

    chrono::system_clock::time_point start_time = chrono::system_clock::now();
    double start_temp = 50, end_temp = 10;
    while (true)
    {
        chrono::system_clock::time_point now_time = chrono::system_clock::now();
        double elapsed = chrono::duration_cast<chrono::milliseconds>(now_time - start_time).count() / 1000;
        if (elapsed > TIME_LIMIT)
            break;

        vector<advertisement> new_ad = pre_ad;
        vector<vector<bool>> new_exists = pre_exists;

        if (modify(new_ad, new_exists) == -1)
            continue;
        int new_score = calculate_score(new_ad);
        int pre_score = calculate_score(pre_ad);

        double temp = start_temp + (end_temp - start_temp) * elapsed;
        double prob = exp((new_score - pre_score) / temp);
        if (prob > (rand() % INF) / (double)INF)
        {
            pre_ad = new_ad;
            pre_exists = new_exists;
        }
    }
    copy(pre_ad.begin(), pre_ad.end(), ad.begin());
}

int main()
{
    cin >> n;
    ad.resize(n);
    rep (i, n)
        cin >> ad[i].x >> ad[i].y >> ad[i].r, ad[i].num = i, exists[ad[i].x][ad[i].x] = true;

    place_ad();

    rep (i, n)
        printf("%d %d %d %d\n", ad[i].a, ad[i].b, ad[i].c, ad[i].d);
    generate_input_file();
    generate_output_file();
    cout << "score: " << calculate_score(ad) << endl;
    return 0;
}