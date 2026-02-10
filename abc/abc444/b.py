n, k = map(int, input().split())
ans = 0
for i in range(1, n + 1):
    total = sum([int(c) for c in str(i)])
    if total == k:
        ans += 1
print(ans)
