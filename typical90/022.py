import math
a, b, c = map(int, input().split())
size = math.gcd(math.gcd(a, b), c)
print(a // size + b // size + c // size - 3)
