#include <stdio.h>
#include <stdlib.h>

int compare_int(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

int main(void) {
    int n;
    scanf("%d", &n);
    int a[100];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    qsort(a, n, sizeof(int), compare_int);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = ans + (i % 2 == 0 ? a[i] : -a[i]);
    }

    printf("%d\n", ans);
    return 0;
}