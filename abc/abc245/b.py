import random

n = int(input())
R = random.randint(0, 1 << 60)
a = sorted({int(num) ^ R for num in input().split()})
for i in range(2001 + 1):
    if i ^ R not in a:
        print(i)
        break
