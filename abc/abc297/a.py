n, d = map(int, input().split())
a = list(map(int, input().split()))

for i in range(n - 1):
    if a[i + 1] - a[i] > d:
        continue
    print(a[i + 1])
    quit()

print(-1)
