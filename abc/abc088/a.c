#include <stdio.h>

int main(void) {
    int n, a;
    scanf("%d", &n);
    scanf("%d", &a);
    
    puts(a >= n % 500 ? "Yes" : "No");
    return 0;
}