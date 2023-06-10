#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

int main() {
    int W, H, N;
    std::cin >> W >> H >> N;
    std::vector<int> p(N), q(N);
    for (int i = 0; i < N; i++) {
        std::cin >> p[i] >> q[i];
    }

    int A;
    std::cin >> A;
    std::vector<int> a(A);
    for (int i = 0; i < A; i++) {
        std::cin >> a[i];
    }
    a.push_back(W);

    int B;
    std::cin >> B;
    std::vector<int> b(B);
    for (int i = 0; i < B; i++) {
        std::cin >> b[i];
    }
    b.push_back(H);

    std::map<std::pair<int, int>, int> sb_cnts;
    for (int i = 0; i < N; i++) {
        int sb_x = *std::lower_bound(a.begin(), a.end(), p[i]);
        int sb_y = *std::lower_bound(b.begin(), b.end(), q[i]);
        sb_cnts[{sb_x, sb_y}]++;
    }

    int ans_min = static_cast<int>(sb_cnts.size()) == (A + 1) * (B + 1) ? 1e9 : 0;
    int ans_max = -1;
    for (const auto &sb_cnt : sb_cnts) {
        ans_min = std::min(ans_min, sb_cnt.second);
        ans_max = std::max(ans_max, sb_cnt.second);
    }

    std::cout << ans_min << " " << ans_max << std::endl;
    return 0;
}