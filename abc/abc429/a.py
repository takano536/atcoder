n, m = map(int, input().split())
for i in range(1, n + 1):
    print('OK' if i <= m else 'Too Many Requests')
