n, k = map(int, input().split())
a = list(input().split())
print(' '.join(a[min(k, n):n] + ['0'] * (min(k, n))))
