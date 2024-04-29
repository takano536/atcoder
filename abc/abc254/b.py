n = int(input())
a = [[1], [1, 1]]
for i in range(2, n):
    ai = list()
    for j in range(1, i + 2):
        if j == 1 or j == i + 1:
            ai.append(1)
        else:
            ai.append(a[i - 1][j - 2] + a[i - 1][j - 1])
    a.append(ai)

for i in range(min(len(a), n)):
    print(*a[i])
