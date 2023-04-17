#include <stdio.h>

int main(void) {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    
    if (a + b == c + d) {
        puts("Balanced");
    } else {
        puts(a + b < c + d ? "Right" : "Left");
    }
    
    return 0;
}