a, b, c, d = map(int, input().split())
if a == c:
    print('Yes' if b > d else 'No')
else:
    print('Yes' if a > c else 'No')
