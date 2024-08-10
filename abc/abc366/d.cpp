#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector a(n, std::vector(n, std::vector<int>(n)));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                std::cin >> a[i][j][k];

    std::vector cumsum(n + 1, std::vector(n + 1, std::vector<int>(n + 1)));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                cumsum[i][j][k] =
                    a[i - 1][j - 1][k - 1] +
                    cumsum[i - 1][j][k] +
                    cumsum[i][j - 1][k] +
                    cumsum[i][j][k - 1] -
                    cumsum[i - 1][j - 1][k] -
                    cumsum[i - 1][j][k - 1] -
                    cumsum[i][j - 1][k - 1] +
                    cumsum[i - 1][j - 1][k - 1];

    int q;
    std::cin >> q;

    while (q--) {
        std::vector<int> l(3), r(3);
        for (int i = 0; i < 3; i++) std::cin >> l[i] >> r[i];
        for (int i = 0; i < 3; i++) l[i]--;

        int ans =
            cumsum[r[0]][r[1]][r[2]] -
            cumsum[l[0]][r[1]][r[2]] -
            cumsum[r[0]][l[1]][r[2]] -
            cumsum[r[0]][r[1]][l[2]] +
            cumsum[l[0]][l[1]][r[2]] +
            cumsum[l[0]][r[1]][l[2]] +
            cumsum[r[0]][l[1]][l[2]] -
            cumsum[l[0]][l[1]][l[2]];

        std::cout << ans << std::endl;
    }

    return 0;
}