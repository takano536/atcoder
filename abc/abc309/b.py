n = int(input())
a = [input() for _ in range(n)]

b = [list(s) for s in a]
for i in range(n - 1):
    b[0][i + 1] = a[0][i]
for i in range(n - 1):
    b[i + 1][-1] = a[i][-1]
for i in range(n - 1):
    b[-1][i] = a[-1][i + 1]
for i in range(n - 1):
    b[i][0] = a[i + 1][0]

for l in b:
    print(''.join(l))
