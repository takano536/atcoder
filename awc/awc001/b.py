n, l, r = map(int, input().split())
p = sorted([(-p, i + 1) for i, p in enumerate(map(int, input().split())) if l <= p <= r])
print(-1 if len(p) == 0 else p[0][1])
