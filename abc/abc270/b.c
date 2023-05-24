#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);

    if (abs(x) < abs(y)) {
        // スタートとゴールの間に壁がないとき
        printf("%d\n", abs(x));
    } else if (x * y < 0) {
        // 壁とゴールの間にスタートがあるとき
        printf("%d\n", abs(x));
    } else if (abs(z) > abs(y)) {
        // スタートとゴールの間に壁がある かつ ハンマーが取れないとき
        puts("-1");
    } else if (x * z > 0) {    // ゴールできて、壁を壊す必要があるとき
        // 同符号なのでそのまま x を出力
        printf("%d\n", abs(x));
    } else {
        // 異符号なので x + z * 2 を出力 ハンマーを取りに行くときに往復
        printf("%d\n", abs(x) + abs(z) * 2);
    }

    return 0;
}