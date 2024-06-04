def rotate_90(matrix):
    h, w = len(matrix), len(matrix[0])
    ret = [[''] * h for _ in range(w)]
    for i in range(w):
        for j in range(h):
            ret[i][j] = matrix[h - 1 - j][i]
        ret[i] = ''.join(ret[i])
    return ret


h, w = map(int, input().split())
c = rotate_90([input() for _ in range(h)])
print(*(ci.count('#') for ci in c))
