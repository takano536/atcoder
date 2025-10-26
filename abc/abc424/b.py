n, m, k = map(int, input().split())
status = [0] * n
for _ in range(k):
    a, _ = map(int, input().split())
    a -= 1
    status[a] += 1
    if status[a] == m:
        print(a + 1, end=' ')
print('\n', end='')
