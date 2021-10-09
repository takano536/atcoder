n, p = map(int, input().split())
a = list(map(int, input().split()))

ans = 0
for x in a:
    ans += 1 if x < p else 0

print(ans)
