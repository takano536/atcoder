n, k = map(int, input().split())
a = list(map(int, input().split()))
i = n - k
cnt = 0
while cnt < n:
    print(a[i], end=' ')
    cnt += 1
    i = (i + 1) % n
print()
