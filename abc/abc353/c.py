import bisect

MOD = int(1e8)
n = int(input())
a = list(map(int, input().split()))
sorted_a = sorted(a)

cumsum = [0] * (n + 1)
for i in range(n):
    cumsum[i + 1] = cumsum[i] + a[i]

ans = 0
cnt = 0
for i in range(n):
    ans += cumsum[n] - cumsum[i + 1]
    ans += a[i] * (n - i - 1)
    cnt += n - bisect.bisect_left(sorted_a, MOD - a[i])
    if a[i] >= MOD - a[i]:
        cnt -= 1

cnt //= 2
print(ans - cnt * MOD)
