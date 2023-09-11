n, p, q, r, s = map(int, input().split())
a = list(map(int, input().split()))

p, q, r, s = p - 1, q - 1, r - 1, s - 1
for i in range(n):
    if p <= i <= q:
        print(a[i - p + r], end=' ')
    elif r <= i <= s:
        print(a[i - r + p], end=' ')
    else:
        print(a[i], end=' ')
print('\n', end='')
