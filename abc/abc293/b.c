#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    int *a;
    int i;
    bool *is_called;
    int ans = 0;

    scanf("%d", &n);

    a = (int *)calloc(n, sizeof(int));
    if (a == NULL) {
        return 0;
    }
    is_called = (bool *)calloc(n, sizeof(bool));
    if (is_called == NULL) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; i++) {
        if (is_called[i]) {
            continue;
        }
        is_called[a[i] - 1] = true;
    }

    for (int i = 0; i < n; i++) {
        if (is_called[i]) {
            continue;
        }
        ans++;
    }
    printf("%d\n", ans);
    for (int i = 0; i < n; i++) {
        if (is_called[i]) {
            continue;
        }
        printf("%d ", i + 1);
    }
}