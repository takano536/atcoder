h, w = map(int, input().split())
s = [input() for _ in range(h)]

VECS = ((1, 0), (0, 1), (-1, 0), (0, -1))

is_satisfied = True
for i in range(h):
    for j in range(w):
        if s[i][j] == '.':
            continue
        count = 0
        for di, dj in VECS:
            ni = i + di
            nj = j + dj
            if ni < 0 or ni >= h or nj < 0 or nj >= w:
                continue
            if s[ni][nj] == '#':
                count += 1
        if count != 2 and count != 4:
            is_satisfied = False

print('Yes' if is_satisfied else 'No')
