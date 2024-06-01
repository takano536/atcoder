n, m = map(int, input().split())
a = list(map(int, input().split()))
x_sums = [0] * m
for i in range(n):
    x = list(map(int, input().split()))
    for j in range(m):
        x_sums[j] += x[j]
is_satisfied = True
for x_sum, ai in zip(x_sums, a):
    if x_sum < ai:
        is_satisfied = False
        break
print('Yes' if is_satisfied else 'No')
