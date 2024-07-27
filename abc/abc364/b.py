h, w = map(int, input().split())
s = list(map(int, input().split()))
c = [input() for _ in range(h)]
x = input()

DIRS = {'L': (0, -1), 'R': (0, 1), 'U': (-1, 0), 'D': (1, 0)}
curr = [s[0] - 1, s[1] - 1]
for dir in x:
    next = [curr[0] + DIRS[dir][0], curr[1] + DIRS[dir][1]]
    if 0 <= next[0] < h and 0 <= next[1] < w and c[next[0]][next[1]] != '#':
        curr = next

print(curr[0] + 1, curr[1] + 1)
