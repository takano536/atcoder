n = int(input())
counts = tuple(map(int, input().split()) for _ in range(n))
print(sum((a < b for a, b in counts)))
