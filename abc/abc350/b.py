n, q = map(int, input().split())
t = [x - 1 for x in map(int, input().split())]
is_exists = [True] * n
for x in t:
    is_exists[x] = not is_exists[x]

print(sum(is_exists))
