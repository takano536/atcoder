n = int(input())
x, y = list(), list()
for _ in range(n):
    xi, yi = map(int, input().split())
    x.append(xi), y.append(yi)
print((max(max(x) - min(x), max(y) - min(y)) + 2 - 1) // 2)
