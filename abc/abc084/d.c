#include <stdio.h>

int main(void) {
    int q;
    int l, r;

    int i, j;

    const int MAX_SIZE = 1e5;

    int is_prime[MAX_SIZE + 1];
    int cumsum[MAX_SIZE + 1 + 1];

    for (i = 0; i < MAX_SIZE + 1; i++) {
        is_prime[i] = 1;
    }
    is_prime[0] = 0, is_prime[1] = 0;

    for (i = 2; i <= MAX_SIZE; i++) {
        if (!is_prime[i]) {
            continue;
        }

        for (j = i * 2; j <= MAX_SIZE; j += i) {
            is_prime[j] = 0;
        }
    }

    cumsum[0] = 0;
    for (i = 1; i <= MAX_SIZE + 1; i++) {
        cumsum[i] = cumsum[i - 1];

        if (i % 2 == 0) {
            continue;
        }

        if (is_prime[i] && is_prime[(i + 1) / 2]) {
            cumsum[i]++;
        }
    }

    scanf("%d", &q);
    for (i = 0; i < q; i++) {
        scanf("%d%d", &l, &r);
        printf("%d\n", cumsum[r] - cumsum[l - 1]);
    }
    return 0;
}