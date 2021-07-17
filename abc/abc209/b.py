import math

n, x = map(int, input().split())
a = list(map(int, input().split()))
print('Yes' if x >= sum(a) - math.floor(len(a) / 2) else 'No')
