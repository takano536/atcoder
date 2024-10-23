n, c = map(int, input().split())
t = list(map(int, input().split()))

ans = 1
prev = t[0]
for ti in t:
    if ti - prev >= c:
        ans += 1
        prev = ti

print(ans)
