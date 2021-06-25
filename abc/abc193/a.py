from decimal import Decimal

n, x = input().split()
n = Decimal(n)
x = Decimal(x)
print(100 - x / n * 100)
