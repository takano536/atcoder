n = int(input())
a = list(input() for _ in range(n))

is_correct = True
for i in range(n):
    for j in range(n):
        if i == j:
            continue
        if a[i][j] == a[j][i] == 'D':
            continue
        if a[i][j] == 'W' and a[j][i] == 'L':
            continue
        if a[i][j] == 'L' and a[j][i] == 'W':
            continue
        is_correct = False

print('correct' if is_correct else 'incorrect')
