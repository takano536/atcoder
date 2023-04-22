n, t = map(int, input().split())
c = list(map(int, input().split()))
r = list(map(int, input().split()))

color = t if t in c else c[0]
print(r.index(max([r[i] for i, c in enumerate(c) if c == color])) + 1)
