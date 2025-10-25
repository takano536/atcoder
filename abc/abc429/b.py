n, m = map(int, input().split())
a = list(map(int, input().split()))

total = sum(a)
is_satisfied = False
for ai in a:
    if total - ai == m:
        is_satisfied = True

print('Yes' if is_satisfied else 'No')
