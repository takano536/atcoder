#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    int i;
    int a;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        if (a % 2) {
            continue;
        }
        printf("%d ", a);
    }
    putchar('\n');
}