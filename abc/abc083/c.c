#include <stdio.h>

int main(void) {
    long long x, y;
    int ans;

    scanf("%lld%lld", &x, &y);

    for (ans = 0; x <= y; x *= 2) {
        ans++;
    }

    printf("%d", ans);
    return 0;
}