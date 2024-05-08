x, y, n = map(int, input().split())
ans = 1e9
for i in range(n + 1):
    for j in range(n + 1):
        if i + 3 * j == n:
            ans = min(x * i + y * j, ans)
print(ans)
