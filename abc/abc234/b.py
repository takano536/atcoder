n = int(input())
coords = [tuple(map(int, input().split())) for _ in range(n)]
ans = 0
max_len = 0

for x1, y1 in coords:
    for x2, y2 in coords:
        if x1 == x2 and y1 == y2:
            continue
        curr_len = (x1 - x2) ** 2 + (y1 - y2) ** 2
        if curr_len > max_len:
            max_len = curr_len
            ans = max_len ** (1 / 2)
print(ans)
