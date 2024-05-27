NA = -1
N = 10

s = [input() for _ in range(N)]

i1, j1 = NA, NA
for i in range(N):
    for j in range(N):
        if s[i][j] == '#':
            i1, j1 = i + 1, j + 1
            break
    if i1 != NA and j1 != NA:
        break


i2, j2 = NA, NA
for i in range(N - 1, -1, -1):
    for j in range(N - 1, -1, -1):
        if s[i][j] == '#':
            i2, j2 = i + 1, j + 1
            break
    if i2 != NA and j2 != NA:
        break

print(i1, i2)
print(j1, j2)
