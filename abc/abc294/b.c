#include <stdio.h>

int main(void)
{
    int h, w;
    int a;
    int i, j;
    
    scanf("%d %d", &h, &w);

    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            scanf("%d", &a);
            
            if (a == 0) {
                putchar('.');
            } else {
                putchar((char)((int)'A' + a - 1));
            }
        }
        putchar('\n');
    }
    return 0;
}