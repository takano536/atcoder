#include <iostream>
#include <map>
#include <vector>

int main() {
    long long h, w, m;
    std::cin >> h >> w >> m;

    std::vector<long long> t(m), a(m), x(m);
    for (int i = 0; i < m; i++) {
        std::cin >> t[i] >> a[i] >> x[i];
        a[i]--;
    }

    std::vector<long long> unpainted_cnts_h(w, h), unpainted_cnts_w(h, w);
    std::map<int, long long> color_cnts;

    long long painted_cnt_offset_h = 0, painted_cnt_offset_w = 0;
    for (int i = m - 1; i >= 0; i--) {
        if (t[i] == 1 && unpainted_cnts_w[a[i]] - painted_cnt_offset_w > 0) {
            color_cnts[x[i]] += unpainted_cnts_w[a[i]] - painted_cnt_offset_w;
            unpainted_cnts_w[a[i]] = 0;
            painted_cnt_offset_h++;
        }
        if (t[i] == 2 && unpainted_cnts_h[a[i]] - painted_cnt_offset_h > 0) {
            color_cnts[x[i]] += unpainted_cnts_h[a[i]] - painted_cnt_offset_h;
            unpainted_cnts_h[a[i]] = 0;
            painted_cnt_offset_w++;
        }
    }

    long long all_sum = 0;
    long long cnts_size = 0;
    for (const auto &[key, value] : color_cnts) {
        if (value <= 0) {
            continue;
        }
        if (key == 0) {
            continue;
        }
        cnts_size++;
        all_sum += value;
    }
    long long zero_cnt = h * w - all_sum;
    if (zero_cnt > 0) {
        cnts_size++;
    }

    std::cout << cnts_size << std::endl;
    if (zero_cnt > 0) {
        std::cout << 0 << ' ' << zero_cnt << std::endl;
    }
    for (const auto &[key, value] : color_cnts) {
        if (key == 0) {
            continue;
        }
        if (value > 0) {
            std::cout << key << ' ' << value << std::endl;
        }
    }
    return 0;
}