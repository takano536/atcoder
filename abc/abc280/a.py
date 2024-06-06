h, w = map(int, input().split())
print(sum([input().count('#') for _ in range(h)]))
