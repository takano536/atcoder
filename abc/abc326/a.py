x, y = map(int, input().split())
print('Yes' if 1 <= (y - x) <= 2 or 1 <= (x - y) <= 3 else 'No')
