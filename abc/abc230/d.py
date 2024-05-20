n, d = map(int, input().split())
walls = [list(map(int, input().split())) for _ in range(n)]
walls = sorted([(right, left) for left, right in walls])
walls = [(left, right) for right, left in walls]

ans = 0
curr_column = walls[0][1]
curr_idx = 0
while curr_idx < n:
    ans += 1
    curr_column = walls[curr_idx][1] + d
    while walls[curr_idx][0] < curr_column:
        curr_idx += 1
        if curr_idx >= n:
            break

print(ans)
