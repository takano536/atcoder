#include <iostream>
#include <vector>

int main() {
    int h, w, n;
    std::cin >> h >> w >> n;

    std::vector<std::vector<int>> snow_increases(h, std::vector<int>(w));
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        std::cin >> a >> b >> c >> d;
        a--, b--, c--, d--;
        snow_increases[a][b]++;
        if (b + 1 < w) {
            snow_increases[a][d + 1]--;
        }
        if (c + 1 < h) {
            snow_increases[c + 1][b]--;
        }
        if (b + 1 < w && c + 1 < h) {
            snow_increases[c + 1][d + 1]++;
        }
    }

    std::vector<std::vector<int>> snow_accumulation(h, std::vector<int>(w));
    for (int i = 0; i < h; i++) {
        int curr_increase = 0;
        for (int j = 0; j < w; j++) {
            curr_increase += snow_increases[i][j];
            snow_accumulation[i][j] += curr_increase;
        }
    }
    snow_increases = snow_accumulation;
    snow_accumulation = std::vector<std::vector<int>>(h, std::vector<int>(w));
    for (int j = 0; j < w; j++) {
        int curr_increase = 0;
        for (int i = 0; i < h; i++) {
            curr_increase += snow_increases[i][j];
            snow_accumulation[i][j] += curr_increase;
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            std::cout << snow_accumulation[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    return 0;
}