import math

INF = int(1e18)
a, b = map(int, input().split())
ans = math.lcm(a, b)
print('Large' if ans > INF else ans)
