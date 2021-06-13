#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

filesystem::path p = filesystem::current_path();

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
vector<advertisement> vertical_ad, horizontal_ad, ans_ad;

int generate_input_file()
{
    ofstream ofs(p.parent_path().string<char>() + "/tools/src/bin/out/input.txt");
    if (!ofs)
        return -1;
    ofs << n << endl;
    rep (i, n)
        ofs << ans_ad[i].x << ' ' << ans_ad[i].y << ' ' << ans_ad[i].r << endl;
    return 0;
}

int generate_output_file()
{
    ofstream ofs(p.parent_path().string<char>() + "/tools/src/bin/out/output.txt");
    if (!ofs)
        return -1;
    rep (i, n)
        ofs << ans_ad[i].a << ' ' << ans_ad[i].b << ' ' << ans_ad[i].c << ' ' << ans_ad[i].d << endl;
    return 0;
}

int calculate_score(vector<advertisement> ad)
{
    long double sum = 0;
    rep (i, n)
    {
        int s = (ad[i].c - ad[i].a) * (ad[i].d - ad[i].b);
        long double p = 1 - (1 - double(min(ad[i].r, s)) / max(ad[i].r, s)) * (1 - double(min(ad[i].r, s)) / max(ad[i].r, s));
        sum += p;
    }
    return round(sum / n * 1e9);
}

bool is_overlapped(int num1, int num2)
{
    int dist_x = abs(ans_ad[num1].x - ans_ad[num2].x);
    int dist_y = abs(ans_ad[num1].y - ans_ad[num2].y);
    double size_x = double(ans_ad[num1].x + ans_ad[num2].x) / 2;
    double size_y = double(ans_ad[num1].y + ans_ad[num2].y) / 2;
    if (dist_x < size_x && dist_y < size_y)
        return true;
    return false;
}

void place_vertival_ad()
{
    sort(vertical_ad.begin(), vertical_ad.end(), x_asc);
    vertical_ad[0].a = vertical_ad[0].x, vertical_ad[0].c = vertical_ad[0].x + 1;
    if (vertical_ad[0].x == vertical_ad[1].x)
    {
        if (vertical_ad[0].y + 1 <= vertical_ad[0].r)
        {
            vertical_ad[0].b = 0;
            vertical_ad[0].d = min(vertical_ad[0].r, vertical_ad[1].y);
        }
        else
        {
            vertical_ad[0].b = vertical_ad[0].y + 1 - vertical_ad[0].r;
            vertical_ad[0].d = vertical_ad[0].y + 1;
        }
    }
    else
    {
        if (vertical_ad[0].y + 1 <= vertical_ad[0].r)
        {
            vertical_ad[0].b = 0;
            vertical_ad[0].d = min(vertical_ad[0].r, 10000);
        }
        else
        {
            vertical_ad[0].b = vertical_ad[0].y + 1 - vertical_ad[0].r;
            vertical_ad[0].d = vertical_ad[0].y + 1;
        }
    }
    rep (i, n - 2)
    {
        vertical_ad[i + 1].a = vertical_ad[i + 1].x, vertical_ad[i + 1].c = vertical_ad[i + 1].x + 1;
        if (vertical_ad[i + 1].x != vertical_ad[i].x && vertical_ad[i + 1].x != vertical_ad[i + 2].x)
        {
            if (vertical_ad[i + 1].y + 1 <= vertical_ad[i + 1].r)
            {
                vertical_ad[i + 1].b = 0;
                vertical_ad[i + 1].d = min(vertical_ad[i + 1].r, 10000);
            }
            else
            {
                vertical_ad[i + 1].b = vertical_ad[i + 1].y + 1 - vertical_ad[i + 1].r;
                vertical_ad[i + 1].d = vertical_ad[i + 1].y + 1;
            }
        }
        else if (vertical_ad[i + 1].x != vertical_ad[i].x && vertical_ad[i + 1].x == vertical_ad[i + 2].x)
        {
            if (vertical_ad[i + 1].y + 1 <= vertical_ad[i + 1].r)
            {
                vertical_ad[i + 1].b = 0;
                vertical_ad[i + 1].d = min(vertical_ad[i + 1].r, vertical_ad[i + 2].y);
            }
            else
            {
                vertical_ad[i + 1].b = vertical_ad[i + 1].y + 1 - vertical_ad[i + 1].r;
                vertical_ad[i + 1].d = vertical_ad[i + 1].y + 1;
            }
        }
        else if (vertical_ad[i + 1].x == vertical_ad[i].x && vertical_ad[i + 1].x != vertical_ad[i + 2].x)
        {
            if (vertical_ad[i + 1].y + 1 - vertical_ad[i].d <= vertical_ad[i + 1].r)
            {
                vertical_ad[i + 1].b = vertical_ad[i].d;
                vertical_ad[i + 1].d = min(vertical_ad[i + 1].b + vertical_ad[i + 1].r, 10000);
            }
            else
            {
                vertical_ad[i + 1].b = vertical_ad[i + 1].y + 1 - vertical_ad[i + 1].r;
                vertical_ad[i + 1].d = vertical_ad[i + 1].y + 1;
            }
        }
        else
        {
            if (vertical_ad[i + 1].y + 1 - vertical_ad[i].d <= vertical_ad[i + 1].r)
            {
                vertical_ad[i + 1].b = vertical_ad[i].d;
                vertical_ad[i + 1].d = min(vertical_ad[i + 1].b + vertical_ad[i + 1].r, vertical_ad[i + 2].y);
            }
            else
            {
                vertical_ad[i + 1].b = vertical_ad[i + 1].y + 1 - vertical_ad[i + 1].r;
                vertical_ad[i + 1].d = vertical_ad[i + 1].y + 1;
            }
        }
    }
    vertical_ad[n - 1].a = vertical_ad[n - 1].x, vertical_ad[n - 1].c = vertical_ad[n - 1].x + 1;
    if (vertical_ad[n - 1].x == vertical_ad[n - 2].x)
    {
        if (vertical_ad[n - 1].y + 1 - vertical_ad[n - 2].d <= vertical_ad[n - 1].r)
        {
            vertical_ad[n - 1].b = vertical_ad[n - 2].d;
            vertical_ad[n - 1].d = min(vertical_ad[n - 1].b + vertical_ad[n - 1].r, 10000);
        }
        else
        {
            vertical_ad[n - 1].b = vertical_ad[n - 1].y + 1 - vertical_ad[n - 1].r;
            vertical_ad[n - 1].d = vertical_ad[n - 1].y + 1;
        }
    }
    else
    {
        if (vertical_ad[n - 1].y + 1 <= vertical_ad[n - 1].r)
        {
            vertical_ad[n - 1].b = 0;
            vertical_ad[n - 1].d = min(vertical_ad[n - 1].r, 10000);
        }
        else
        {
            vertical_ad[n - 1].b = vertical_ad[n - 1].y + 1 - vertical_ad[n - 1].r;
            vertical_ad[n - 1].d = vertical_ad[n - 1].y + 1;
        }
    }
    sort(vertical_ad.begin(), vertical_ad.end(), num_asc);
}

void place_horizontal_ad()
{
    sort(horizontal_ad.begin(), horizontal_ad.end(), y_asc);
    horizontal_ad[0].b = horizontal_ad[0].y, horizontal_ad[0].d = horizontal_ad[0].y + 1;
    if (horizontal_ad[0].y == horizontal_ad[1].y)
    {
        if (horizontal_ad[0].x + 1 <= horizontal_ad[0].r)
        {
            horizontal_ad[0].a = 0;
            horizontal_ad[0].c = min(horizontal_ad[0].r, horizontal_ad[1].x);
        }
        else
        {
            horizontal_ad[0].a = horizontal_ad[0].x + 1 - horizontal_ad[0].r;
            horizontal_ad[0].c = horizontal_ad[0].x + 1;
        }
    }
    else
    {
        if (horizontal_ad[0].x + 1 <= horizontal_ad[0].r)
        {
            horizontal_ad[0].a = 0;
            horizontal_ad[0].c = min(horizontal_ad[0].r, 10000);
        }
        else
        {
            horizontal_ad[0].a = horizontal_ad[0].x + 1 - horizontal_ad[0].r;
            horizontal_ad[0].c = horizontal_ad[0].x + 1;
        }
    }
    rep (i, n - 2)
    {
        horizontal_ad[i + 1].b = horizontal_ad[i + 1].y, horizontal_ad[i + 1].d = horizontal_ad[i + 1].y + 1;
        if (horizontal_ad[i + 1].y != horizontal_ad[i].y && horizontal_ad[i + 1].y != horizontal_ad[i + 2].y)
        {
            if (horizontal_ad[i + 1].x + 1 <= horizontal_ad[i + 1].r)
            {
                horizontal_ad[i + 1].a = 0;
                horizontal_ad[i + 1].c = min(horizontal_ad[i + 1].r, 10000);
            }
            else
            {
                horizontal_ad[i + 1].a = horizontal_ad[i + 1].x + 1 - horizontal_ad[i + 1].r;
                horizontal_ad[i + 1].c = horizontal_ad[i + 1].x + 1;
            }
        }
        else if (horizontal_ad[i + 1].y != horizontal_ad[i].y && horizontal_ad[i + 1].y == horizontal_ad[i + 2].y)
        {
            if (horizontal_ad[i + 1].x + 1 <= horizontal_ad[i + 1].r)
            {
                horizontal_ad[i + 1].a = 0;
                horizontal_ad[i + 1].c = min(horizontal_ad[i + 1].r, horizontal_ad[i + 2].x);
            }
            else
            {
                horizontal_ad[i + 1].a = horizontal_ad[i + 1].x + 1 - horizontal_ad[i + 1].r;
                horizontal_ad[i + 1].c = horizontal_ad[i + 1].x + 1;
            }
        }
        else if (horizontal_ad[i + 1].y == horizontal_ad[i].y && horizontal_ad[i + 1].y != horizontal_ad[i + 2].y)
        {
            if (horizontal_ad[i + 1].x + 1 - horizontal_ad[i].c <= horizontal_ad[i + 1].r)
            {
                horizontal_ad[i + 1].a = horizontal_ad[i].c;
                horizontal_ad[i + 1].c = min(horizontal_ad[i + 1].a + horizontal_ad[i + 1].r, 10000);
            }
            else
            {
                horizontal_ad[i + 1].a = horizontal_ad[i + 1].x + 1 - horizontal_ad[i + 1].r;
                horizontal_ad[i + 1].c = horizontal_ad[i + 1].x + 1;
            }
        }
        else
        {
            if (horizontal_ad[i + 1].x + 1 - horizontal_ad[i].c <= horizontal_ad[i + 1].r)
            {
                horizontal_ad[i + 1].a = horizontal_ad[i].c;
                horizontal_ad[i + 1].c = min(horizontal_ad[i + 1].a + horizontal_ad[i + 1].r, horizontal_ad[i + 2].x);
            }
            else
            {
                horizontal_ad[i + 1].a = horizontal_ad[i + 1].x + 1 - horizontal_ad[i + 1].r;
                horizontal_ad[i + 1].c = horizontal_ad[i + 1].x + 1;
            }
        }
    }
    horizontal_ad[n - 1].b = horizontal_ad[n - 1].y, horizontal_ad[n - 1].d = horizontal_ad[n - 1].y + 1;
    if (horizontal_ad[n - 1].y == horizontal_ad[n - 2].y)
    {
        if (horizontal_ad[n - 1].x + 1 - horizontal_ad[n - 2].c <= horizontal_ad[n - 1].r)
        {
            horizontal_ad[n - 1].a = horizontal_ad[n - 2].c;
            horizontal_ad[n - 1].c = min(horizontal_ad[n - 1].a + horizontal_ad[n - 1].r, 10000);
        }
        else
        {
            horizontal_ad[n - 1].a = horizontal_ad[n - 1].x + 1 - horizontal_ad[n - 1].r;
            horizontal_ad[n - 1].c = horizontal_ad[n - 1].x + 1;
        }
    }
    else
    {
        if (horizontal_ad[n - 1].x + 1 <= horizontal_ad[n - 1].r)
        {
            horizontal_ad[n - 1].a = 0;
            horizontal_ad[n - 1].c = min(horizontal_ad[n - 1].r, 10000);
        }
        else
        {
            horizontal_ad[n - 1].a = horizontal_ad[n - 1].x + 1 - horizontal_ad[n - 1].r;
            horizontal_ad[n - 1].c = horizontal_ad[n - 1].x + 1;
        }
    }
    sort(horizontal_ad.begin(), horizontal_ad.end(), num_asc);
}

int main()
{
    cin >> n;
    ans_ad.resize(n), vertical_ad.resize(n), horizontal_ad.resize(n);
    rep (i, n)
    {
        cin >> ans_ad[i].x >> ans_ad[i].y >> ans_ad[i].r;
        ans_ad[i].num = i;
        vertical_ad[i].x = ans_ad[i].x, horizontal_ad[i].x = ans_ad[i].x;
        vertical_ad[i].y = ans_ad[i].y, horizontal_ad[i].y = ans_ad[i].y;
        vertical_ad[i].r = ans_ad[i].r, horizontal_ad[i].r = ans_ad[i].r;
        vertical_ad[i].num = ans_ad[i].num, horizontal_ad[i].num = ans_ad[i].num;
    }

    place_horizontal_ad();
    place_vertival_ad();
    calculate_score(horizontal_ad) > calculate_score(vertical_ad) ? copy(horizontal_ad.begin(), horizontal_ad.end(), ans_ad.begin()) : copy(vertical_ad.begin(), vertical_ad.end(), ans_ad.begin());
    
    rep (i, n)
        printf("%d %d %d %d\n", ans_ad[i].a, ans_ad[i].b, ans_ad[i].c, ans_ad[i].d);
    // cout << calculate_score(vertical_ad) << endl;
    // cout << calculate_score(horizontal_ad) << endl;
    // cout << calculate_score(ans_ad) << endl;
    // generate_input_file();
    // generate_output_file();
    return 0;
}