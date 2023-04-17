#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    int a[200];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int ans = 0;
    int curr_idx = 0;
    while (1) {
        if (a[curr_idx] % 2 == 1) {
            break;
        }
        
        a[curr_idx] /= 2;
        curr_idx++;
        if (curr_idx == n) {
            curr_idx = 0;
            ans++;
        }
    }

    printf("%d", ans);
    return 0;
}