n, l, r = map(int, input().split())
times = tuple(map(int, input().split()) for _ in range(n))
print(sum(x <= l <= r <= y for x, y in times))
