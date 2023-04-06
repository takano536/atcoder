#include <iostream>
#include <vector>

int main() {
    int h, w;
    std::cin >> h >> w;

    std::vector<std::vector<int>> x(h, std::vector<int>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            std::cin >> x[i][j];
        }
    }

    std::vector<std::vector<int>> cumsum(h + 1, std::vector<int>(w + 1));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cumsum[i + 1][j + 1] = cumsum[i][j + 1] + cumsum[i + 1][j] - cumsum[i][j] + x[i][j];
        }
    }

    int q;
    std::cin >> q;
    for (int i = 0; i < q; i++) {
        int a, b, c, d;
        std::cin >> a >> b >> c >> d;
        int ans = cumsum[c][d] - cumsum[a - 1][d] - cumsum[c][b - 1] + cumsum[a - 1][b - 1];
        std::cout << ans << std::endl;
    }
    return 0;
}