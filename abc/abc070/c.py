import math

n = int(input())
t = [int(input()) for _ in range(n)]

ans = t[n - 1]
for i in range(n - 1):
    ans = math.lcm(ans, t[i])

print(ans)
