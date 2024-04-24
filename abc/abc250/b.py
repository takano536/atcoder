n, a, b = map(int, input().split())

is_black = [[False] * n for _ in range(n)]
for i in range(n):
    for j in range(n):
        if i == j == 0:
            continue
        is_black[i][j] = not is_black[i][j - 1] if j > 0 else not is_black[i - 1][j]

ans = [[0] * n * b for _ in range(n * a)]
for i in range(n):
    for j in range(n):
        for ai in range(a):
            for bi in range(b):
                ans[i * a + ai][j * b + bi] = is_black[i][j]

for row in ans:
    print(''.join('#' if x else '.' for x in row))
