#include <iostream>
#include <vector>

int main() {
    int h, w, n, hm, wm;
    std::cin >> h >> w >> n >> hm >> wm;

    std::vector a(h, std::vector<int>(w));
    std::vector<int> cnts(n);
    for (auto &ai : a) {
        for (auto &x : ai) {
            std::cin >> x;
            x--;
            cnts[x]++;
        }
    }

    std::vector cumsums(h + 1, std::vector(w + 1, std::vector<int>(n)));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            for (int k = 0; k < n; k++) {
                cumsums[i + 1][j + 1][k] =
                    cumsums[i][j + 1][k] +
                    cumsums[i + 1][j][k] -
                    cumsums[i][j][k] +
                    (a[i][j] == k ? 1 : 0);
            }
        }
    }

    for (int i = 0; i <= h - hm; i++) {
        for (int j = 0; j <= w - wm; j++) {
            int ans = n;
            std::vector<int> curr_cnts = cnts;
            for (int k = 0; k < n; k++) {
                curr_cnts[k] -=
                    cumsums[i + hm][j + wm][k] -
                    cumsums[i][j + wm][k] -
                    cumsums[i + hm][j][k] +
                    cumsums[i][j][k];
                if (curr_cnts[k] == 0) ans--;
            }
            std::cout << ans << ' ';
        }
        std::cout << std::endl;
    }
    return 0;
}