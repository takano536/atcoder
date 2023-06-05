#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);

    if (1 <= n && n <= 9) {
        printf("AGC00%d", n);
    }
    if (10 <= n && n <= 41) {
        printf("AGC0%d", n);
    }
    if (n >= 42) {
        printf("AGC0%d", n + 1);
    }
    return 0;
}