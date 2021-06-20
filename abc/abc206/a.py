import math

n = int(input())
ans = int(math.floor(n * 1.08))
if ans == 206:
    print('so-so')
else:
    print('Yay!' if ans < 206 else ':(')
