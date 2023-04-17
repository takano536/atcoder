#include <stdio.h>
#include <stdlib.h>

int compare_int(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);

    int *a = calloc(n, sizeof(int));
    if (a == NULL) {
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int *num_cnts = calloc(n + 1, sizeof(int));
    if (num_cnts == NULL) {
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++) {
        num_cnts[a[i]]++;
    }

    int category_cnt = 0;
    for (int i = 0; i < n + 1; i++) {
        category_cnt += (int)(num_cnts[i] > 0);
    }

    qsort(num_cnts, n + 1, sizeof(int), compare_int);

    int ans = 0;
    int curr_idx = 0;
    while (category_cnt > k) {
        if (num_cnts[curr_idx] == 0) {
            curr_idx++;
            continue;
        }

        ans += num_cnts[curr_idx];
        category_cnt--;
        curr_idx++;
    }

    printf("%d\n", ans);

    free(a);
    free(num_cnts);
    return 0;
}