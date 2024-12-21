DIRS = {'U': (-1, 0), 'D': (1, 0), 'L': (0, -1), 'R': (0, 1)}

h, w, i, j = map(int, input().split())
s = [input() for _ in range(h)]
t = input()
i -= 1
j -= 1

has_visited = set()
ans = 0

for c in t:
    di, dj = DIRS[c]
    ni, nj = i + di, j + dj
    if 0 <= ni < h and 0 <= nj < w and s[ni][nj] != '#':
        i, j = ni, nj
    if s[i][j] == '@' and (i, j) not in has_visited:
        has_visited.add((i, j))
        ans += 1

print(i + 1, j + 1, ans, sep=' ')
