n, a = map(int, input().split())
t = list(map(int, input().split()))

curr = 0
for i in range(n):
    if curr < t[i]:
        curr = t[i]
    curr += a
    print(curr)
