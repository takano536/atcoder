n = int(input())
schedules = [tuple(map(int, input().split())) for _ in range(n)]

q = int(input())
ans = list()
for _ in range(q):
    t, d = map(int, input().split())
    q, r = schedules[t - 1]
    ans.append(((d // q) if d % q <= r else (d // q + 1)) * q + r)

print(*ans, sep='\n')
