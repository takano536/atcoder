n, p, q = map(int, input().split())
d = [price + q for price in map(int, input().split())]
d.append(p)
print(min(d))
