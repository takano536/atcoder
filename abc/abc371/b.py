n, m = map(int, input().split())
exists = [False] * n
for i in range(m):
    a, b = input().split()
    if b == 'F':
        print('No')
        continue
    a = int(a) - 1
    if not exists[a]:
        exists[a] = True
        print('Yes')
    else:
        print('No')
