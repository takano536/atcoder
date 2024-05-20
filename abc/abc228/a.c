#include <stdio.h>

int main(void) {
    int s, t, x;
    int curr;
    int is_satisfied = 0;
    const int MOD = 24;
    
    scanf("%d%d%d", &s, &t, &x);
    curr = s;

    while (curr != t) {
        if (curr == x) is_satisfied = 1;
        curr = (curr + 1) % MOD;
    }

    puts(is_satisfied ? "Yes" : "No");
    return 0;
}