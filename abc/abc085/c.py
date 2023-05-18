n, y = map(int, input().split())

for i in range(n + 1):
    for j in range(n + 1):
        k = max(n - i - j, 0)
        if i + j + k != n:
            continue
        if i * 1e4 + j * 5 * 1e3 + k * 1e3 == y:
            print(f'{i} {j} {k}')
            quit()

print('-1 -1 -1')
