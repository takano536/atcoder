#include <iostream>
#include <vector>

long long count(const std::vector<long long> &a, long long loop_cnt) {
    // mid周したときの食べたリンゴの数を数える
    long long res = 0;
    for (const auto &apple_cnt : a) {
        res += std::min(loop_cnt, apple_cnt);
    }
    return res;
}

int main() {
    int n;
    long long k;
    std::cin >> n >> k;

    std::vector<long long> a(n);
    for (auto &num : a) {
        std::cin >> num;
    }

    long long ok = 0;
    long long ng = 1e12 + 1;

    // 周回する数を二分探索
    while (ng - ok > 1) {
        long long mid = static_cast<double>(ng + ok) / 2;
        if (count(a, mid) <= k) {
            ok = mid;
        } else {
            ng = mid;
        }
    }

    // ok周だとリンゴをピッタリ食い切れていない場合があるので調整
    long long loop_cnt = ok;
    long long offset = k;
    for (auto &apple_cnt : a) {
        offset -= std::min(apple_cnt, loop_cnt);
        apple_cnt -= std::min(apple_cnt, loop_cnt);
    }
    for (int i = 0; i < n && offset > 0; i++) {
        if (a[i] == 0) {
            continue;
        }
        a[i]--;
        offset--;
    }

    for (const auto &ans : a) {
        std::cout << ans << ' ';
    }
    std::cout << std::endl;

    return 0;
}