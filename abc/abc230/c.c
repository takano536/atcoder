#include <stdio.h>

int main(void) {
    long long i, j;

    const int MAX_SIZE = 3 * 1e5 + 10;

    long long n, a, b;
    long long p, q, r, s;

    char ans[MAX_SIZE][MAX_SIZE];
    long long start_idx = -1, end_idx = -1;

    scanf("%lld %lld %lld", &n, &a, &b);
    scanf("%lld %lld %lld %lld", &p, &q, &r, &s);

    for (i = p; i <= q; i++) {
        for (j = r; j <= s; j++) {
            putchar(i + j == a + b || i - j == a - b ? '#' : '.');
        }
        putchar('\n');
    }
    return 0;
}