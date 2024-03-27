import math

n = int(input())
print('Yes' if n * math.log(2) > 2 * math.log(n) else 'No')
