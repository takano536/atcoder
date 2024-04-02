a, b = map(int, input().split())
len = (a ** 2 + b ** 2) ** 0.5
print(f'{a / len:.7f} {b / len:.7f}')
