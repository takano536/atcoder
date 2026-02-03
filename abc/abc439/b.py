n = int(input())

rets = set()
while n != 1 and n not in rets:
    rets.add(n)
    n = sum([int(c) ** 2 for c in str(n)])

print('Yes' if n == 1 else 'No')
