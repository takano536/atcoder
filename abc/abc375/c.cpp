#include <iostream>
#include <string>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::string> a(n);
    for (auto &ai : a) std::cin >> ai;

    std::vector<std::string> b(n, std::string(n, '0'));
    for (int i = 0; i < n / 2; i++) {
        int upper_left = i;
        int lower_right = n - i - 1;
        switch ((i + 1) % 4) {
            case 0:
                // rotate 0
                for (int i = upper_left; i <= lower_right; i++) {
                    b[i][upper_left] = a[i][upper_left];
                    b[i][lower_right] = a[i][lower_right];
                }
                for (int j = upper_left; j <= lower_right; j++) {
                    b[upper_left][j] = a[upper_left][j];
                    b[lower_right][j] = a[lower_right][j];
                }
                break;

            case 1:
                // rotate 90
                for (int i = upper_left; i <= lower_right; i++) {
                    b[i][upper_left] = a[lower_right][i];
                    b[i][lower_right] = a[upper_left][i];
                }
                for (int j = upper_left; j <= lower_right; j++) {
                    b[upper_left][j] = a[n - j - 1][upper_left];
                    b[lower_right][j] = a[n - j - 1][lower_right];
                }
                break;

            case 2:
                // rotate 180
                for (int i = upper_left; i <= lower_right; i++) {
                    b[i][upper_left] = a[n - i - 1][lower_right];
                    b[i][lower_right] = a[n - i - 1][upper_left];
                }
                for (int j = upper_left; j <= lower_right; j++) {
                    b[upper_left][j] = a[lower_right][n - j - 1];
                    b[lower_right][j] = a[upper_left][n - j - 1];
                }
                break;

            case 3:
                // rotate 270
                for (int i = upper_left; i <= lower_right; i++) {
                    b[i][upper_left] = a[upper_left][n - i - 1];
                    b[i][lower_right] = a[lower_right][n - i - 1];
                }
                for (int j = upper_left; j <= lower_right; j++) {
                    b[upper_left][j] = a[j][lower_right];
                    b[lower_right][j] = a[j][upper_left];
                }
                break;
        }
    }

    for (const auto &bi : b) std::cout << bi << std::endl;
    return 0;
}