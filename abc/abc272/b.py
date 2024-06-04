n, m = map(int, input().split())
x = list(set() for _ in range(n))
for i in range(m):
    xi = [xij - 1 for xij in list(map(int, input().split()))[1:]]
    for xij in xi:
        x[xij].add(i)

is_satisfied = True
for i in range(n):
    for j in range(n):
        if i != j and len(x[i] & x[j]) == 0:
            is_satisfied = False

print('Yes' if is_satisfied else 'No')
