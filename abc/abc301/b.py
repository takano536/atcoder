n = int(input())
a = list(map(int, input().split()))

for i in range(n - 1):
    if a[i] - 1 == a[i + 1] or a[i] + 1 == a[i + 1]:
        print(a[i], end=' ')
        continue

    if a[i] < a[i + 1]:
        for ans in range(a[i], a[i + 1]):
            print(ans, end=' ')
            continue
    else:
        for ans in range(a[i], a[i + 1], -1):
            print(ans, end=' ')
            continue
print(a[-1])
