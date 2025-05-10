n, m = map(int, input().split())
counts = [0] * m
a = [x - 1 for x in map(int, input().split())]

for ai in a:
    counts[ai] += 1

for count in counts:
    if count == 0:
        print(0)
        exit()

for i in range(n):
    ai = a.pop()
    counts[ai] -= 1
    if counts[ai] == 0:
        print(i + 1)
        break
