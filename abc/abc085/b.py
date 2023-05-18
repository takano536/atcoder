n = int(input())
d = [int(input()) for _ in range(n)]

size_cnts = dict()
for dirmeter in d:
    size_cnts[dirmeter] = size_cnts.get(dirmeter, 0) + 1

ans = len(size_cnts.keys())
print(ans)
