h, w = map(int, input().split())
s = [input() for _ in range(h)]
coords = list()
for i, si in enumerate(s):
    for j, c in enumerate(si):
        if c == 'o':
            coords.append((i, j))
print(abs(coords[0][0] - coords[1][0]) + abs(coords[0][1] - coords[1][1]))
