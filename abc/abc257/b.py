n, k, q = map(int, input().split())
a = list(map(int, input().split()))
for i in [x - 1 for x in map(int, input().split())]:
    if a[i] == n:
        continue
    if i == k - 1 or (i < k and a[i] + 1 != a[i + 1]):
        a[i] += 1

print(*a)
