x, y = map(int, input().split())
print((x + y) % 12 if (x + y) % 12 > 0 else 12)
