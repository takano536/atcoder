n, m = map(int, input().split())
p, f = list(), list()
for _ in range(n):
    inputs = list(map(int, input().split()))
    p.append(inputs[0])
    f.append(set(inputs[2:]))

satisfied = False

for i, bad in enumerate(zip(p, f)):
    for j, good in enumerate(zip(p, f)):

        if i == j:
            continue

        bad_price, bad_funcs = bad
        good_price, good_funcs = good

        if good_price > bad_price:
            continue

        if good_price == bad_price and good_funcs > bad_funcs:
            satisfied = True
        if good_price < bad_price and good_funcs >= bad_funcs:
            satisfied = True

print('Yes' if satisfied else 'No')
