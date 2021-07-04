a, b, c = map(int, input().split())
total = a + b + c
print(max(max(total - a, total - b), total - c))
