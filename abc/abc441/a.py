p, q = map(int, input().split())
x, y = map(int, input().split())
print('Yes' if p <= x <= p - 1 + 100 and q <= y <= q - 1 + 100 else 'No')
