n = int(input())
a = list(map(int, input().split()))
cumsum = [0] * (n + 1)
for i in range(0, n, 1):
    cumsum[i + 1] = (cumsum[i] + a[i]) % 360
cumsum += [360]
cumsum.sort()
ans = 0
for i in range(n + 1):
    ans = max(ans, cumsum[i + 1] - cumsum[i])
print(ans)
