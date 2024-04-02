a, b, c, d, e, f, x = map(int, input().split())
takahashi = [0] * (x + 1)


def calc_time(a: int, b: int, c: int, x: int) -> int:
    times = [0] * (x + 1)
    for i in range(x):
        times[i + 1] = times[i]
        times[i + 1] += b if 0 <= i % (a + c) <= a else 0
    return times[x]


takahashi = calc_time(a, b, c, x)
aoki = calc_time(d, e, f, x)
if takahashi == aoki:
    print('Draw')
else:
    print('Takahashi' if takahashi > aoki else 'Aoki')
