n, m, x, t, d = map(int, input().split())
for i in range(n, -1, -1):
    if i < x:
        t -= d
    if i == m:
        break
print(t)
