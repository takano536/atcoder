r, c = [x - 1 for x in map(int, input().split())]
print([list(map(int, input().split())) for _ in range(2)][r][c])
