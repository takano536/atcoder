n = int(input())
a = list(map(int, input().split()))

if n == 2:
    print('Yes')
    exit()

is_satisfied = True
for i in range(n - 2):
    if a[i] * a[i + 2] != a[i + 1] ** 2:
        is_satisfied = False
        break

print('Yes' if is_satisfied else 'No')
