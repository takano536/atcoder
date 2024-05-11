n, k = map(int, input().split())
a = list(map(int, input().split()))
ans = 0
i = 0
curr = 0
while i < n:
    if curr + a[i] > k:
        ans += 1
        curr = 0
    else:
        curr += a[i]
        i += 1
print(ans + 1)
