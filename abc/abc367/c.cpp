#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    constexpr int MAX_N = 8;

    int n, k;
    std::cin >> n >> k;

    std::vector<int> r(n);
    for (auto &ri : r) std::cin >> ri;

    while (n < MAX_N) r.push_back(0), n++;

    for (int i0 = 0; i0 <= r[0]; i0++) {
        if (r[0] != 0 && i0 == r[0]) continue;
        for (int i1 = 0; i1 <= r[1]; i1++) {
            if (r[1] != 0 && i1 == r[1]) continue;
            for (int i2 = 0; i2 <= r[2]; i2++) {
                if (r[2] != 0 && i2 == r[2]) continue;
                for (int i3 = 0; i3 <= r[3]; i3++) {
                    if (r[3] != 0 && i3 == r[3]) continue;
                    for (int i4 = 0; i4 <= r[4]; i4++) {
                        if (r[4] != 0 && i4 == r[4]) continue;
                        for (int i5 = 0; i5 <= r[5]; i5++) {
                            if (r[5] != 0 && i5 == r[5]) continue;
                            for (int i6 = 0; i6 <= r[6]; i6++) {
                                if (r[6] != 0 && i6 == r[6]) continue;
                                for (int i7 = 0; i7 <= r[7]; i7++) {
                                    if (r[7] != 0 && i7 == r[7]) continue;
                                    int sum = i0 + 1;
                                    sum += r[1] > 0 ? i1 + 1 : 0;
                                    sum += r[2] > 0 ? i2 + 1 : 0;
                                    sum += r[3] > 0 ? i3 + 1 : 0;
                                    sum += r[4] > 0 ? i4 + 1 : 0;
                                    sum += r[5] > 0 ? i5 + 1 : 0;
                                    sum += r[6] > 0 ? i6 + 1 : 0;
                                    sum += r[7] > 0 ? i7 + 1 : 0;
                                    if (sum % k != 0) continue;
                                    std::string ans = std::to_string(i0 + 1);
                                    ans += std::to_string(r[1] > 0 ? i1 + 1 : 0);
                                    ans += std::to_string(r[2] > 0 ? i2 + 1 : 0);
                                    ans += std::to_string(r[3] > 0 ? i3 + 1 : 0);
                                    ans += std::to_string(r[4] > 0 ? i4 + 1 : 0);
                                    ans += std::to_string(r[5] > 0 ? i5 + 1 : 0);
                                    ans += std::to_string(r[6] > 0 ? i6 + 1 : 0);
                                    ans += std::to_string(r[7] > 0 ? i7 + 1 : 0);
                                    while (ans.back() == '0') ans.pop_back();
                                    for (const auto &c : ans) std::cout << c << ' ';
                                    std::cout << std::endl;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}