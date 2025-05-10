def rotate_90(matrix):
    h, w = len(matrix), len(matrix[0])
    ret = [[''] * h for _ in range(w)]
    for i in range(w):
        for j in range(h):
            ret[i][j] = matrix[h - 1 - j][i]
        ret[i] = ''.join(ret[i])
    return ret


n = int(input())
s = [input() for _ in range(n)]
t = [input() for _ in range(n)]

ans = 1e9
for k in range(4):
    count = k
    for i in range(n):
        for j in range(n):
            if s[i][j] != t[i][j]:
                count += 1
    ans = min(ans, count)
    s = rotate_90(s)

print(ans)
