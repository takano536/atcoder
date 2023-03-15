h, w = map(int, input().split())
a = list()
for _ in range(h):
    a.append(list(map(int, input().split())))

distance = [[1, 0], [0, 1]]
passed_ways = [[[] for _ in range(w)] for _ in range(h)]
passed_ways[0][0].append(str(a[0][0]))

is_visited = [[False] * w for _ in range(h)]
for y in range(h):
    for x in range(w):
        current_passed_ways = passed_ways[y][x]
        is_visited[y][x] = True
        for dy, dx in distance:
            if y + dy >= h or x + dx >= w:
                continue
            if is_visited[y + dy][x + dx]:
                continue
            passed_ways[y + dy][x + dx].extend([" ".join([way, str(a[y + dy][x + dx])]) for way in current_passed_ways])

ans = 0
for goal_way in passed_ways[h - 1][w - 1]:
    saw_nums = list(map(int, goal_way.split()))
    if len(saw_nums) == len(set(saw_nums)):
        ans += 1

print(ans)
