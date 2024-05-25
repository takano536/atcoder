n, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
c = sorted(a + b)

is_satisfied = False
for i in range(n + m - 1):
    if c[i] in a and c[i + 1] in a:
        is_satisfied = True
        break

print('Yes' if is_satisfied else 'No')
