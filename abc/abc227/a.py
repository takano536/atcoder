n, k, a = map(int, input().split())
ans = a - 1
for _ in range(k - 1):
    ans += 1
    ans %= n
print(ans + 1)
