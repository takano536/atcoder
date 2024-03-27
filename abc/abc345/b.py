import decimal

x = decimal.Decimal(input())
ans = (x / 10).to_integral_exact(rounding=decimal.ROUND_CEILING)
print(0 if ans == 0 else ans)
