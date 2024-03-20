a, b = [''.join(reversed(list(s))) for s in input().split()]
print('Easy' if all([int(a[i]) + int(b[i]) < 10 for i in range(min(len(a), len(b)))]) else 'Hard')
