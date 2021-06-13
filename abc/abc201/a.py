a = list(map(int, input().split(' ')))
a = sorted(a)
print('Yes' if a[1] - a[0] == a[2] - a[1] else 'No')
