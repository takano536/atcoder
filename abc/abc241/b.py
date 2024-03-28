n, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

is_satisfied = True
for size in b:
    if size in a:
        a.remove(size)
    else:
        is_satisfied = False
print('Yes' if is_satisfied else 'No')
