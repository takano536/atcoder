n, k = map(int, input().split())
a = [(ai, i) for i, ai in enumerate(map(int, input().split()))]
b = {bi - 1 for bi in map(int, input().split())}
a.sort(reverse=True)
max_a = a[0][0]
is_satisified = False
for a, i in a:
    if a != max_a:
        break
    if i in b:
        is_satisified = True
print('Yes' if is_satisified else 'No')
