#include <stdio.h>

int main(void) {
    char s[4];
    scanf("%s", s);

    int ans = 0;
    for (int i = 0; i < 3; i++) {
        if (s[i] == '1') {
            ans++;
        }
    }

    printf("%d\n", ans);
    return 0;
}