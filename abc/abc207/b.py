import math

a, b, c, d = map(int, input().split())
print(max(math.ceil(a / (c * d - b)), -1) if c * d - b != 0 else -1)
