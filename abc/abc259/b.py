import math

a, b, d = map(int, input().split())
rad = math.radians(d)
x = math.cos(rad) * a - math.sin(rad) * b
y = math.sin(rad) * a + math.cos(rad) * b
print(f'{x:.07f} {y:.07f}')
