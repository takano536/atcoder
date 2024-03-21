n = int(input())
cnts = dict()
for _ in range(n):
    s = input()
    if cnts.get(s) is None:
        cnts[s] = 1
    else:
        cnts[s] += 1
print(max(cnts, key=cnts.get))
