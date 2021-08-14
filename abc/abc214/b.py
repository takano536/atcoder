s, t = map(int, input().split())
ans = 0
for i in range(100 + 1):
    for j in range(100 + 1):
        for k in range(100 + 1):
            if i + j + k <= s and i * j * k <= t:
                ans += 1
print(ans)
