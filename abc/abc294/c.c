#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int num;
    int idx;
    int rank;
    bool is_a;
} tuple_t;

int compaer_num(const void *n1, const void *n2)
{
    if (((tuple_t *)n1)->num > ((tuple_t *)n2)->num) {
        return 1;
    } else {
        return -1;
    }
}

int main(void)
{
    int n, m;
    int i;
    scanf("%d%d", &n, &m);

    tuple_t *c;
    c = (tuple_t *)malloc((n + m) * sizeof(tuple_t));
    if (c == NULL) {
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < n; i++) {
        scanf("%d", &c[i].num);
        c[i].idx = i;
        c[i].rank = -1;
        c[i].is_a = true;
    }
    for (; i < n + m; i++) {
        scanf("%d", &c[i].num);
        c[i].idx = i;
        c[i].rank = -1;
        c[i].is_a = false;
    }

    qsort(c, n + m, sizeof(tuple_t), compaer_num);
    for (int i = 0; i < n + m; i++) {
        c[i].rank = i + 1;
    }

    for (int i = 0; i < n + m; i++) {
        if (c[i].is_a) {
            printf("%d ", c[i].rank);
        }
    }
    putchar('\n');
    for (int i = 0; i < n + m; i++) {
        if (!c[i].is_a) {
            printf("%d ", c[i].rank);
        }
    }
    putchar('\n');

    free(c);
    return 0;
}