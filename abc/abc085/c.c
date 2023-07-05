#include <stdio.h>

int main(void) {
    int n, y;
    int i, j, k;
    int ans_10k = -1, ans_5k = -1, ans_1k = -1;

    scanf("%d%d", &n, &y);

    for (i = 0; i * 10000 <= y; i++) {
        for (j = 0; i * 10000 + j * 5000 <= y; j++) {
            k = n - i - j;
            if (k < 0) {
                continue;
            }
            if (i * 10000 + j * 5000 + k * 1000 == y) {
                ans_10k = i, ans_5k = j, ans_1k = k;
            }
        }
    }

    printf("%d %d %d\n", ans_10k, ans_5k, ans_1k);
    return 0;
}