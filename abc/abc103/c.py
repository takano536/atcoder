import math

n = int(input())
a = list(map(int, input().split()))

m = a[0]
for i in range(1, n):
    m = math.lcm(m, a[i])
m -= 1

print(sum([m % ai for ai in a]))
