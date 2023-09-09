def f(n, i) -> str:
    for j in range(1, 9 + 1):
        if n % j == 0 and i % (n / j) == 0:
            return str(j)
    return '-'


n = int(input())
print(''.join([f(n, i) for i in range(n + 1)]))
