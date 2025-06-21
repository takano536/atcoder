n = int(input())
d = list(map(int, input().split()))

for i in range(n - 1):
    curr = d[i]
    print(curr, end=' ')
    for j in range(i + 1, n - 1):
        curr = curr + d[j]
        print(curr, end=' ')
    print('\n', end='')
