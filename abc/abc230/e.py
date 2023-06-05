from math import isqrt
n = int(input())
print(2 * sum(n // i for i in range(1, isqrt(n) + 1)) - isqrt(n) ** 2)
