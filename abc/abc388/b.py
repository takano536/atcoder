n, d = map(int, input().split())
snakes = [tuple(map(int, input().split())) for _ in range(n)]

for i in range(1, d + 1):
    ans = 0
    for t, l in snakes:
        ans = max(ans, t * (l + i))
    print(ans)
