#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int i;
    int n = -1;
    bool satisfies = false;
    bool ok = true;

    char s[10 + 1];
    scanf("%s", s);

    n = strlen(s);

    for (int i = 0; i < 3; i++) {
        ok = true;
        for (int j = 0; j < n; j++) {
            if (j % 3 == i && s[j] != 'o') {
                ok = false;
            }
            if (j % 3 != i && s[j] != 'x') {
                ok = false;
            }
        }
        if (ok) {
            satisfies = true;
        }
    }

    puts(satisfies ? "Yes" : "No");
    return 0;
}