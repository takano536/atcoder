#include <stdbool.h>
#include <stdio.h>

int main(void) {
    const int N_MAX = 1e5;
    const long long ANS_MAX = 1e18;

    int n;
    scanf("%d", &n);

    long long a[N_MAX];
    bool is_zero = false;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if (a[i] == 0) {
            is_zero = true;
        }
    }

    if (is_zero) {
        puts("0");
        return 0;
    }

    long long ans = a[0];
    for (int i = 1; i < n; i++) {
        if ((long double)ANS_MAX / a[i] < ans) {
            puts("-1");
            return 0;
        }

        ans *= a[i];
    }

    printf("%lld\n", ans);
    return 0;
}