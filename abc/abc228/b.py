n, x = map(int, input().split())
a = [int(i) - 1 for i in input().split()]

is_visited = [False] * n
i = x - 1
ans = 0
while not is_visited[i]:
    is_visited[i] = True
    ans += 1
    i = a[i]

print(ans)
