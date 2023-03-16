#include <stdio.h>
#include <string.h>

int main(void)
{
    int i;
    char s[128];
    int size = 0;
    char ans[128] = "";
    scanf("%s", s);

    size = strlen(s);
    for (i = 0; i < size; i += 2) {
        ans[i] = s[i + 1];
        ans[i + 1] = s[i];
    }

    printf("%s", ans);
}