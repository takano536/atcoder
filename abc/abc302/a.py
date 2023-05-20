from decimal import Decimal, ROUND_UP

a, b = input().split()
print((Decimal(a) / Decimal(b)).quantize(Decimal('0'), rounding=ROUND_UP))
