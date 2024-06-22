#include <cmath>
#include <iostream>
#include <vector>

int main() {
    long long sx, sy, tx, ty;
    std::cin >> sx >> sy >> tx >> ty;

    long long ans = 0;

    long long dy = std::abs(ty - sy);
    long long dx = std::abs(tx - sx);
    if (dy > dx) {
        ans = dy;
    } else {
        if (sx < tx) {
            if (std::abs(sy) % 2 == 0 && std::abs(sx) % 2 == 0) sx++;
            if (std::abs(sy) % 2 == 1 && std::abs(sx) % 2 == 1) sx++;
            sx += dy;
            ans += dy;
            ans += std::ceil(static_cast<double>(tx - sx) / 2);
        } else {
            if (std::abs(sy) % 2 == 0 && std::abs(sx) % 2 == 1) sx--;
            if (std::abs(sy) % 2 == 1 && std::abs(sx) % 2 == 0) sx--;
            sx -= dy;
            ans += dy;
            ans += ((sx - tx) + 2 - 1) / 2;
        }
    }

    std::cout << ans << std::endl;
    return 0;
}