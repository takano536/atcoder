v, a, b, c = map(int, input().split())
id = 'FMT'
usage = [a, b, c]
curr_v = v
i = 0
while curr_v - usage[i] >= 0:
    curr_v -= usage[i]
    i = (i + 1) % len(usage)
print(id[i])
