primes = set()
for i in range(2, 200 + 1):
    for j in range(2, i):
        if i % j == 0:
            break
    else:
        primes.add(i)
a, b, c, d = map(int, input().split())
is_won = False
for i in range(a, b + 1):
    is_satisfied = True
    for j in range(c, d + 1):
        if i + j in primes:
            is_satisfied = False
    if is_satisfied:
        is_won = True
print('Takahashi' if is_won else 'Aoki')
