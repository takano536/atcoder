h, w = map(int, input().split())
r, c = [x - 1 for x in map(int, input().split())]

ans = 0
for i, j in ((1, 0), (0, 1), (-1, 0), (0, -1)):
    if 0 <= r + i < h and 0 <= c + j < w:
        ans += 1
print(ans)
