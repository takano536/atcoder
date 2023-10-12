n = int(input())
rects = [list(map(int, input().split())) for _ in range(n)]

is_covered = [[False] * (100 + 1) for _ in range(100 + 1)]

for rect in rects:
    for i in range(rect[0], rect[1]):
        for j in range(rect[2], rect[3]):
            is_covered[i][j] = True

print(sum(sum(is_covered, [])))
