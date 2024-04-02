import random

R = random.randint(0, 1 << 60)
n = input()
print(len({a ^ R for a in map(int, input().split())}))
