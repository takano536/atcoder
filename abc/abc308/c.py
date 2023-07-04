from decimal import Decimal

n = int(input())
probs = list()
for i in range(n):
    a, b = input().split()
    probs.append((Decimal(a) / (Decimal(a) + Decimal(b)), -1 * i))

probs.sort()
probs.reverse()

for prob in probs:
    _, ans = prob
    print(-1 * ans + 1, end=' ')
print(end='\n')
