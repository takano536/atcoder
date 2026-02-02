n = int(input())
t = sorted(list((ti, i + 1) for i, ti in enumerate(map(int, input().split()))))
for i in range(3):
    _, ans = t[i]
    print(ans, end=' ')
print('\n', end='')
