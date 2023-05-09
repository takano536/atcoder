#include <stdio.h>

int main(void) {
    long long a;
    int b_int, b_dec;
    scanf("%lld %d.%d", &a, &b_int, &b_dec);

    printf("%lld\n", a * (b_int*100 + b_dec) / 100);
    return 0;
}