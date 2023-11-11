n, x = map(int, input().split())
print(sum([int(s) for s in input().split() if int(s) <= x]))
