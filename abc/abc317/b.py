n = int(input())
a = sorted(list(map(int, input().split())))

for i in range(n - 1):
    if a[i + 1] - 1 != a[i]:
        print(a[i] + 1)
        break
